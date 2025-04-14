#include "sorting_algorithms.h"

void MergeSort::merge(std::vector<int>& input, int l, int m, int r){
    int len_1 = m - l + 1;
    int len_2 = r - m;
    std::vector<int> left(len_1 + 1);
    std::vector<int> right(len_2 + 1);
    for (int i = 0; i < len_1; i++){
        left[i] = input[l + i];
    }
    for (int j = 0; j < len_2; j++){
        right[j] = input[m + j + 1];
    }
    left[len_1] = INF;
    right[len_2] = INF;
    int i = 0, j = 0;
    for (int k = l; k <= r; k++) {
        if (left[i] <= right[j]) {
            input[k] = left[i];
            i++;
        }else {
            input[k] = right[j];
            j++;
        }
    }
}
void MergeSort::sort(std::vector<int>& input, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        sort(input, l, m);
        sort(input, m + 1, r);
        merge(input, l, m, r);
    }
}