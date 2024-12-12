#ifndef INMEM_H
#define INMEM_H

#include <string>
#include <unordered_map>

class InMem {
private:
    std::unordered_map<std::string, int> database;
    std::unordered_map<std::string, int> transaction;
    bool transaction_in_progress = false;

public:
    int get(const std::string& key);
    void put(const std::string& key, int val);
    void begin_transaction();
    void commit();
    void rollback();
};

#endif
