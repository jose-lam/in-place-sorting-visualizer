#include "../include/InsertionSort.hpp"

InsertionSort::InsertionSort() : Sorter("Insertion Sort") {}

void InsertionSort::sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1 ; i < n ; ++i){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0){
            ++operations;
            if (!(arr[j] > key))
                break;
            ++operations;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
