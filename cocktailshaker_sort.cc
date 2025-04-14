#include "sorting_algorithms.h"

void CocktailShakerSort::sort (std::vector<int>& input) {
    bool swapped = true;
    int start = 0, end = input.size() - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (input[i] > input[i + 1]) {
                int tmp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = tmp;
                swapped = true;
            }
        }
        end--;

        if (!swapped)   break;
        swapped = false;
        for (int i = end; i > start; i--) {
            if (input[i] < input[i - 1]) {
                int tmp = input[i];
                input[i] = input[i - 1];
                input[i - 1] = tmp;
                swapped = true;
            }
        }
        start++;
    }
}
