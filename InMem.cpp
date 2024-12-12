#include "InMemoryDB.h"
#include <iostream>
#include <unordered_map>
#include <stdexcept>

class InMemoryDBImpl : public InMemoryDB {
    int get(const std::string& key) override {
        if (transaction_in_progress && transaction.find(key) != transaction.end()) {
            return transaction[key];
        }
        if (database.find(key) != database.end()) {
            return database[key];
        }
        throw std::runtime_error("Key not found");
    }

    void put(const std::string& key, int val) override {
        if (!transaction_in_progress) {
            throw std::runtime_error("No transaction in progress");
        }
        transaction[key] = val;
    }

    void begin_transaction() override {
        if (transaction_in_progress) {
            throw std::runtime_error("Transaction is already in progress");
        }
        transaction.clear();
        transaction_in_progress = true;
    }

    void commit() override {
        if (!transaction_in_progress) {
            throw std::runtime_error("No transaction in progress");
        }
        for (const auto& pair : transaction) {
            database[pair.first] = pair.second;
        }
        transaction_in_progress = false;
    }

    void rollback() override {
        if (!transaction_in_progress) {
            throw std::runtime_error("No transaction in progress");
        }
        transaction.clear();
        transaction_in_progress = false;
    }
};
