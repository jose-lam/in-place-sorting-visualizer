#ifndef SHELLSORT_HPP
#define SHELLSORT_HPP

#include "Sorter.hpp"

class ShellSort : public Sorter {
public:
    ShellSort();

    void sort(std::vector<int>& arr) override;
};

#endif
