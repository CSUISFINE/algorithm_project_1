#include "sorting_algorithms.h"

void SelectionSort::sort(std::vector<int>& input) {
    int n = input.size();
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (input[min_idx] > input[j]) {
                min_idx = j;
            }
        }
        int tmp = input[min_idx];
        input[min_idx] = input[i];
        input[i] = tmp;
    }
}