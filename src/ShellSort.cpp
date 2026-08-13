#include "../include/ShellSort.hpp"


ShellSort::ShellSort() : Sorter("Shell Sort") {}

void ShellSort::sort(std::vector<int>& arr) {
    size_t gaps = 0;
    size_t n = arr.size();

    while (gaps < n/3) gaps = gaps * 3 + 1;

    while (gaps > 0) {
        for (size_t i = gaps; i < n; ++i) {
            int temp = arr[i];
            size_t j = i;

            while (true) {
                ++operations;
                if (!(j >= gaps && arr[j - gaps] > temp))
                    break;
                arr[j] = arr[j - gaps];
                ++operations;
                j -= gaps;
            }
            arr[j] = temp;
        }
        gaps = (gaps - 1) / 3;
    }
}
