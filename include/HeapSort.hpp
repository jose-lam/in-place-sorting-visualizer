#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include "Sorter.hpp"

class HeapSort : public Sorter {
public:
    HeapSort();

    void sort(std::vector<int>& arr) override;

private:
    void heapify(std::vector<int>& arr, int n, int rootIndex);
};

#endif
