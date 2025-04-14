#include "sorting_algorithms.h"

void BubbleSort::sort(std::vector<int>& input) {
    int n = input.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (input[j] > input[j + 1]) {
                int tmp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = tmp;
            }
        }
    }
}