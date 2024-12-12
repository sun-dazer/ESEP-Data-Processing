#ifndef INMEM_H
#define INMEM_H

#include <string>

class InMem {
private:
    std::unordered_map<std::string, int> database;
    std::unordered_map<std::string, int> transaction;
    bool transaction_in_progress = false;
public:
    virtual int get(const std::string& key) = 0;
    virtual void put(const std::string& key, int val) = 0;
    virtual void begin_transaction() = 0;
    virtual void commit() = 0;
    virtual void rollback() = 0;
    virtual ~InMem() = default;
};

#endif 
