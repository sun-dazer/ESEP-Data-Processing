#include "InMem.h"
#include <stdexcept>
int InMem::get(const std::string& key) {
    if (transaction_in_progress && transaction.find(key) != transaction.end()) {
        return transaction[key];
    }
    if (database.find(key) != database.end()) {
        return database[key];
    }
    throw std::runtime_error("Key not found");
}
void InMem::put(const std::string& key, int val) {
    if (!transaction_in_progress) {
        throw std::runtime_error("No transaction in progress");
    }
    transaction[key] = val;
}
void InMem::begin_transaction() {
    if (transaction_in_progress) {
        throw std::runtime_error("A transaction is already in progress");
    }
    transaction.clear();
    transaction_in_progress = true;
}
void InMem::commit() {
    if (!transaction_in_progress) {
        throw std::runtime_error("No transaction in progress");
    }
    for (const auto& pair : transaction) {
        database[pair.first] = pair.second;
    }
    transaction_in_progress = false;
}
void InMem::rollback() {
    if (!transaction_in_progress) {
        throw std::runtime_error("No transaction in progress");
    }
    transaction.clear();
    transaction_in_progress = false;
}
