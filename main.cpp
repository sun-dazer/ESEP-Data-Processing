#include "InMem.h"
#include <iostream>

int main() { // Incomplete test code as an example.
    InMem db;

    try {
        std::cout << db.get("A") << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl; 
    }

    try {
        db.put("A", 5);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl; 
    }
    return 0;
}
