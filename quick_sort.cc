#include "sorting_algorithms.h"

int QuickSort::partition (std::vector<int>& input, int p, int r){
    int x = input[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (input[j] <= x){
            i++;
            int tmp = input[i];
            input[i] = input[j];
            input[j] = tmp;
        }
    }
    int tmp = input[i + 1];
    input[i + 1] = input[r];
    input[r] = tmp;
    return i + 1;
}
void QuickSort::sort_intro_version (std::vector<int>& input, int p, int r, int max_depth){
    if (p < r) {
        if (max_depth == 0) {
            HeapSort heapsort;
            heapsort.sort_intro_version(input, r - p + 1);
            return;
        }

        int q = partition(input, p, r);
        sort_intro_version(input, p, q - 1, max_depth - 1);
        sort_intro_version(input, q + 1, r, max_depth - 1);
    }
}
void QuickSort::sort (std::vector<int>& input, int p, int r){
    if (p < r) {
        int q = partition(input, p, r);
        sort(input, p, q - 1);
        sort(input, q + 1, r);
    }
}
