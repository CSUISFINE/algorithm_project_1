#include "sorting_algorithms.h"

void HeapSort::max_heapify(std::vector<int>& input, int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;
    if (l < n && input[l] > input[i]) {
        largest = l;
    }else {
        largest = i;
    }
    if (r < n && input[r] > input[largest]) {
        largest = r;
    }
    if (largest != i) {
        int tmp = input[i];
        input[i] = input[largest];
        input[largest] = tmp;
        max_heapify(input, n, largest);
    }
}

void HeapSort::sort_intro_version(std::vector<int>& input, int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        max_heapify(input, n, i);
    }
    for (int i = n - 1; i >= 0; i--){
        int tmp = input[0];
        input[0] = input[i];
        input[i] = tmp;
        max_heapify(input, i, 0);
    }
}
void HeapSort::sort(std::vector<int>& input){
    for (int i = input.size() / 2 - 1; i >= 0; i--){
        max_heapify(input, input.size(), i);
    }
    for (int i = input.size() - 1; i >= 0; i--){
        int tmp = input[0];
        input[0] = input[i];
        input[i] = tmp;
        max_heapify(input, i, 0);
    }
}
