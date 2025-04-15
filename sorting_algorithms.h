#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

class MergeSort {
    const int INF = std::numeric_limits<int>::max();
public:
    void merge(std::vector<int>& input, int l, int m, int r);
    void sort(std::vector<int>& data, int l, int r);
};

class HeapSort {
    void max_heapify(std::vector<int>& input, int n, int i);
public:
    void sort_intro_version(std::vector<int>& input, int n);
    void sort(std::vector<int>& input);
};

class BubbleSort {
public:
    void sort(std::vector<int>& data);
};

class InsertionSort {
public:
    void sort(std::vector<int>& data, int left, int right);
};

class SelectionSort {
public:
    void sort(std::vector<int>& data);
};

class QuickSort {
    int partition (std::vector<int>& input, int p, int r);
public:
    void sort_intro_version (std::vector<int>& input, int p, int r, int max_depth);
    void sort (std::vector<int>& input, int p, int r);
};

class LibrarySort {
    const int GAP = std::numeric_limits<int>::min();
    int binary_search(const std::vector<int>& array, int begin, int end, int value);
    void rebalance(std::vector<int>& array, int begin, int end);
    void insert(std::vector<int>& array, int pos, int value, int end);
public:
    void sort(std::vector<int>& input);
};

class TimSort {
public:
    void sort(std::vector<int>& data);
};

class CocktailShakerSort {
public:
    void sort(std::vector<int>& data);
};

class CombSort {
public:
    void sort(std::vector<int>& data);
};

class TournamentSort {
    const int INF = std::numeric_limits<int>::max();
    int match(std::vector<int>& input, int p1, int p2);
    std::vector<int> build_tree(std::vector<int>& input);
    void update_tree(std::vector<int>& input, std::vector<int>& tree, int p);
public:
    void sort(std::vector<int>& data);
};

class IntroSort {
public:
    void sort (std::vector<int>& input);
};

#endif
