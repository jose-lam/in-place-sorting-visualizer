#include "../include/HeapSort.hpp"
#include <utility>

HeapSort::HeapSort() : Sorter("Heap Sort") {}

void HeapSort::sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n/2 - 1 ; i >= 0 ; --i)
        heapify(arr, n, i);
    for (int i = n-1 ; i > 0 ; --i){
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void HeapSort::heapify(std::vector<int>& arr, int n, int rootIndex) {
    int left = 2 * rootIndex + 1;
    int right = left + 1;
    int mayor = rootIndex;

    if (left < n){
        ++operations;
        if (arr[left] > arr[mayor])
            mayor = left;
    }
    if (right < n){
        ++operations;
        if (arr[right] > arr[mayor])
            mayor = right;
    }
    if (mayor != rootIndex){
        ++operations;
        std::swap(arr[rootIndex], arr[mayor]);
        heapify(arr, n, mayor);
    }
}
