#include "sorting_algorithms.h"

void TimSort::sort(std::vector<int>& input){
    int n = input.size();
    int run = 32;
    int i = 0, left = 0, size = run;
    InsertionSort insertionsort;
    MergeSort mergesort;

    while (i < n) {
        insertionsort.sort(input, i, std::min(i + run - 1, n - 1));
        i = i + run;
    }

    while (size < n) {
        while (left < n) {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);
            if (mid < right) {
                mergesort.merge(input, left, mid, right);
            }
            left += 2 * size;
        }
        left = 0;
        size = 2 * size;
    }
}