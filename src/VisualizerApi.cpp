#include "../include/VisualizerApi.hpp"

#include <iostream>
#include <random>
#include <limits>

namespace VisualizerApi {

std::size_t requestArraySize() {
    constexpr std::size_t minN = 10;
    constexpr std::size_t maxN = 10'000'000;

    std::size_t n = 0;

    while (true) {
        std::cout << "Enter array size n (" << minN << " <= n <= " << maxN << "): ";
        std::cin >> n;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
            continue;
        }

        if (n < minN || n > maxN) {
            std::cout << "Value out of range. Try again.\n";
            continue;
        }

        break;
    }

    return n;
}

std::vector<int> generateRandomData(std::size_t n) {
    std::vector<int> data(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, static_cast<int>(n));

    for (std::size_t i = 0; i < n; ++i) {
        data[i] = dist(gen);
    }

    return data;
}

void run() {
    // To be completed in later sprints (algorithm execution + dashboard)
}

}
