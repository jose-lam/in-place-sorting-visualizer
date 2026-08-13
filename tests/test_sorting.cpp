#include "../include/ShellSort.hpp"
#include "../include/HeapSort.hpp"
#include "../include/InsertionSort.hpp"

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <string>

namespace {

std::vector<int> generateTestData(std::size_t n) {
    std::vector<int> data(n);
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(1, static_cast<int>(n));

    for (std::size_t i = 0; i < n; ++i) {
        data[i] = dist(gen);
    }
    return data;
}

bool testSorter(Sorter& sorter, const std::vector<int>& original,
                 const std::vector<int>& expected) {
    std::vector<int> data = original;
    sorter.sort(data);

    if (data != expected) {
        std::cerr << "[FAIL] " << sorter.getName()
                   << " output does not match std::sort result.\n";
        return false;
    }

    std::cout << "[PASS] " << sorter.getName()
              << " matches std::sort for n = " << original.size() << "\n";
    return true;
}

bool testSmallCaseAllAlgorithms() {
    constexpr std::size_t n = 2000;

    std::vector<int> original = generateTestData(n);
    std::vector<int> expected = original;
    std::sort(expected.begin(), expected.end());

    ShellSort shellSort;
    HeapSort heapSort;
    InsertionSort insertionSort;

    bool ok = true;
    ok &= testSorter(shellSort, original, expected);
    ok &= testSorter(heapSort, original, expected);
    ok &= testSorter(insertionSort, original, expected);

    return ok;
}

bool testMaxCaseExcludingInsertionSort() {
    constexpr std::size_t n = 10'000'000;

    std::vector<int> original = generateTestData(n);
    std::vector<int> expected = original;
    std::sort(expected.begin(), expected.end());

    ShellSort shellSort;
    HeapSort heapSort;

    bool ok = true;
    ok &= testSorter(shellSort, original, expected);
    ok &= testSorter(heapSort, original, expected);

    return ok;
}

}

int main() {
    bool allPassed = true;

    allPassed &= testSmallCaseAllAlgorithms();
    allPassed &= testMaxCaseExcludingInsertionSort();

    if (!allPassed) {
        std::cerr << "\nSome tests FAILED.\n";
        return 1;
    }

    std::cout << "\nAll tests PASSED.\n";
    return 0;
}
