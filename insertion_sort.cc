#include "sorting_algorithms.h"

void InsertionSort::sort(std::vector<int>& input, int left, int right){
    int i = left + 1;
    while (i <= right) {
        int tmp = input[i];
        int j = i - 1;
        while (j >= left && input[j] > tmp) {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = tmp;
        i++;
    }
}