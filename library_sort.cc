#include "sorting_algorithms.h"

int LibrarySort::binary_search(const std::vector<int>& array, int begin, int end, int value) {
    int left = begin;
    int right = end;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == GAP) {
            // move to left and find nonempty position.
            int temp_mid = mid;
            while (temp_mid >= left && array[temp_mid] == GAP) {
                temp_mid--;
            }
            
            if (temp_mid >= left) {
                if (array[temp_mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
                continue;
            }
            
            // move to right and find nonempty position.
            temp_mid = mid;
            while (temp_mid <= right && array[temp_mid] == GAP) {
                temp_mid++;
            }
            
            if (temp_mid <= right) {
                if (array[temp_mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
                continue;
            }
            
            return mid;
        }
        
        if (array[mid] == value) {
            return mid + 1;
        } else if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}
    
// rebalance (assume that epsilon = 1)
void LibrarySort::rebalance(std::vector<int>& array, int begin, int end) {
    int r = end;
    int w = end * 2;
    
    while (r >= begin) {
        array[w] = array[r];
        array[w-1] = GAP;
        r--;
        w -= 2;
    }
}

void LibrarySort::insert(std::vector<int>& array, int pos, int value, int end) {
    int insert_pos = pos;
    if (pos > end) {
        insert_pos--;
        while (array[insert_pos] != GAP) {
            insert_pos--;
        }
        for (int i = insert_pos; i < pos - 1; i++) {
            array[i] = array[i + 1];
        }
        array[pos - 1] = value;
        return;
    }

    if (array[pos] == GAP) {
        array[pos] = value;
        return;
    }

    while (insert_pos < array.size() && array[insert_pos] != GAP) {
        insert_pos++;
    }

    if(insert_pos > end) {
        insert_pos = pos;
        while (array[insert_pos] != GAP) {
            insert_pos--;
        }
        for (int i = insert_pos; i < pos - 1; i++) {
            array[i] = array[i + 1];
        }
        array[pos - 1] = value;
        return;
    }
    
    if (insert_pos < array.size()) {
        for (int i = insert_pos; i > pos; i--) {
            array[i] = array[i - 1];
        }
        array[pos] = value;
    }
}

void LibrarySort::sort(std::vector<int>& input) {
    int n = input.size();
    
    std::vector<int> sorted_arr(2 * n + 1, GAP);
    
    sorted_arr[1] = input[0];
    
    for (int i = 1; i <= static_cast<int>(log2(n - 1)) + 1; i++) {
        // rebalance 1 to 2^(i-1)
        rebalance(sorted_arr, 1, static_cast<int>(pow(2, i - 1)));
        // find position and insert for 2^(i-1) to 2^i - 1
        for (int j = static_cast<int>(pow(2, i - 1)); j < std::min(static_cast<int>(pow(2, i)), n); j++) {
            int ins = binary_search(sorted_arr, 1, static_cast<int>(pow(2, i)), input[j]);
            insert(sorted_arr, ins, input[j], static_cast<int>(pow(2, i)));
        }
    }
    std::vector<int> result;
    for (int val : sorted_arr) {
        if (val != GAP) {
            result.push_back(val);
        }
    }
    input = result;
}