#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>

std::string randomItem(const std::vector<std::string> &arr) {
    // Seed the random number generator with current time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, arr.size() - 1);

    int randomIndex = distribution(generator);
    return arr[randomIndex];
}

std::string randomItem(std::vector<std::string> &&arr) {
    // Seed the random number generator with current time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, arr.size() - 1);

    int randomIndex = distribution(generator);
    return std::move(arr[randomIndex]);
}

int main() {
    std::vector<std::string> items = {"apple", "banana", "cherry", "date", "elderberry"};

    std::string randomLValueItem = randomItem(items);
    std::cout << "Random LValue Item: " << randomLValueItem << std::endl;

    std::string randomRValueItem = randomItem(std::vector<std::string>{"grape", "kiwi", "lemon","weeknd","travis","reminder"});
    std::cout << "Random RValue Item: " << randomRValueItem << std::endl;

    return 0;
}
