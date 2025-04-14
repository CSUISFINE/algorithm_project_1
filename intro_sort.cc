#include "sorting_algorithms.h"

void IntroSort::sort (std::vector<int>& input) {
    int max_depth = 2 * static_cast<int>(log2(input.size()));
    QuickSort quicksort;
    InsertionSort insertionsort;
    quicksort.sort_intro_version(input, 0, input.size() - 1, max_depth);
    insertionsort.sort(input, 0, input.size() - 1);
}