#ifndef SHOPSYSTEM_H
#define SHOPSYSTEM_H

#include <iostream>

class ShopSystem {
public:
    void visit(int& money) {
        std::cout << "[SHOP] offered: Bonus(+2) cost 2\n";
        if (money >= 2) {
            money -= 2;
            std::cout << "[SHOP] purchased! money: " << money << "\n";
        }
        else {
            std::cout << "[SHOP] skipped (not enough money)\n";
        }
    }
};

#endif // SHOPSYSTEM_H
