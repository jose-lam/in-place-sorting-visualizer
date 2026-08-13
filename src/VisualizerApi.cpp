#include "../include/VisualizerApi.hpp"
#include "../include/Sorter.hpp"
#include "../include/ShellSort.hpp"
#include "../include/HeapSort.hpp"
#include "../include/InsertionSort.hpp"

#include <iostream>
#include <iomanip>
#include <random>
#include <limits>
#include <chrono>
#include <cmath>
#include <memory>

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

long long computeTheoreticalOperations(const std::string& algorithmName, std::size_t n) {
    double nd = static_cast<double>(n);

    if (algorithmName == "Shell Sort") {
        return static_cast<long long>(std::pow(nd, 1.5));
    }
    if (algorithmName == "Heap Sort") {
        return static_cast<long long>(nd * std::log2(nd));
    }
    if (algorithmName == "Insertion Sort") {
        return static_cast<long long>(nd * nd);
    }

    return 0;
}

std::vector<AlgorithmResult> executeAlgorithms(const std::vector<int>& originalData) {
    constexpr std::size_t insertionSortLimit = 100'000;
    std::size_t n = originalData.size();

    std::vector<std::unique_ptr<Sorter>> sorters;
    sorters.push_back(std::make_unique<ShellSort>());
    sorters.push_back(std::make_unique<HeapSort>());
    sorters.push_back(std::make_unique<InsertionSort>());

    std::vector<AlgorithmResult> results;

    for (auto& sorter : sorters) {
        AlgorithmResult result;
        result.name = sorter->getName();
        result.theoreticalOperations = computeTheoreticalOperations(sorter->getName(), n);
        result.skipped = false;

        if (sorter->getName() == "Insertion Sort" && n > insertionSortLimit) {
            result.skipped = true;
            result.skipReason = "N exceeds " + std::to_string(insertionSortLimit) + " (O(N^2) would freeze the machine)";
            result.elapsedMicroseconds = 0.0;
            result.realOperations = 0;
            results.push_back(result);
            continue;
        }

        std::vector<int> dataCopy = originalData;

        auto start = std::chrono::high_resolution_clock::now();
        sorter->sort(dataCopy);
        auto end = std::chrono::high_resolution_clock::now();

        result.elapsedMicroseconds =
            std::chrono::duration<double, std::micro>(end - start).count();
        result.realOperations = sorter->getOperations();

        results.push_back(result);
    }

    return results;
}

void renderDashboard(const std::vector<AlgorithmResult>& results, std::size_t n) {
    std::cout << "\n";
    std::cout << " IN-PLACE SORTING VISUALIZER - DASHBOARD (n = " << n << ")\n";
    std::cout << std::left
               << std::setw(18) << "Algorithm"
               << std::setw(15) << "Time"
               << std::setw(20) << "Theoretical Ops"
               << std::setw(20) << "Real Ops"
               << "\n";

    for (const auto& r : results) {
        if (r.skipped) {
            std::cout << std::left << std::setw(18) << r.name
                       << "SKIPPED - " << r.skipReason << "\n";
            continue;
        }

        std::string timeStr;
        if (r.elapsedMicroseconds >= 1000.0) {
            timeStr = std::to_string(r.elapsedMicroseconds / 1000.0) + " ms";
        } else {
            timeStr = std::to_string(r.elapsedMicroseconds) + " us";
        }

        std::cout << std::left
                   << std::setw(18) << r.name
                   << std::setw(15) << timeStr
                   << std::setw(20) << r.theoreticalOperations
                   << std::setw(20) << r.realOperations
                   << "\n";
    }

}

void run() {
    std::size_t n = requestArraySize();
    std::vector<int> originalData = generateRandomData(n);

    std::vector<AlgorithmResult> results = executeAlgorithms(originalData);

    renderDashboard(results, n);
}

}
