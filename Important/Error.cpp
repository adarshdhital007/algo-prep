#include <iostream>

class Cake {
public:
    Cake() {
        std::cout << "Baking a cake..." << std::endl;
        // Constructor: Baking the cake (basic setup)
    }

    void prepare() {
        std::cout << "Preparing the cake..." << std::endl;
        // Prepare the cake (additional setup)
    }

    virtual void decorate() {
        std::cout << "Decorating the cake." << std::endl;
        // Virtual method for decoration
    }
};

class SpecialCake : public Cake {
public:
    SpecialCake() {
        std::cout << "Baking a special cake..." << std::endl;
    }

    void prepare() {
        std::cout << "Preparing the special cake..." << std::endl;
    }

    void decorate() override {
        std::cout << "Decorating the special cake." << std::endl;
    }
};

int main() {
    Cake basicCake;
    basicCake.prepare();
    basicCake.decorate();

    SpecialCake specialCake;
    specialCake.prepare();
    specialCake.decorate();

    return 0;
}
