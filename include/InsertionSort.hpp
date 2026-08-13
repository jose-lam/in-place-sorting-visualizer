#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include "Sorter.hpp"

class InsertionSort : public Sorter {
public:
    InsertionSort();

    void sort(std::vector<int>& arr) override;
};

#endif
