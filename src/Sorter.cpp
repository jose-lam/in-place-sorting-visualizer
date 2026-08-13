#include "../include/Sorter.hpp"

Sorter::Sorter(std::string algorithmName)
    : name(std::move(algorithmName)), operations(0) {}

const std::string& Sorter::getName() const {
    return name;
}

long long Sorter::getOperations() const {
    return operations;
}
