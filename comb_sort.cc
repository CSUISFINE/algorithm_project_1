#include "sorting_algorithms.h"

void CombSort::sort (std::vector<int>& input) {
    int gap = input.size();
    double shrink = 1.3;
    bool sorted = false;

    while (!sorted) {
        gap = static_cast<int>((double)gap / shrink);

        if (gap > 1) {
            sorted = false;
        }else {
            gap = 1;
            sorted = true;
        }

        int i = 0;
        while (i + gap < input.size()) {
            if (input[i] > input[i + gap]) {
                int tmp = input[i];
                input[i] = input[i + gap];
                input[i + gap] = tmp;
                sorted = false;
            }
            i++;
        }
    }
}
