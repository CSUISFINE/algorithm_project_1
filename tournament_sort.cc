#include "sorting_algorithms.h"

int TournamentSort::match(std::vector<int>& input, int p1, int p2) {
    if (input[p1] <= input[p2]) {
        return p1;
    } else {
        return p2;
    }
}
std::vector<int> TournamentSort::build_tree(std::vector<int>& input) {
    int n = input.size();
    std::vector<int> tree(2 * n);
    for (int i = 0; i < n; i++) {
        tree[n + i] = i;
    }
    for (int i = n - 1; i >= 1; i--) {
        tree[i] = match(input, tree[2 * i], tree[2 * i + 1]);
    }
    return tree;
}
void TournamentSort::update_tree(std::vector<int>& input, std::vector<int>& tree, int p) {
    int tree_idx = p + input.size();
    for (tree_idx = tree_idx / 2; tree_idx >= 1; tree_idx = tree_idx / 2) {
        tree[tree_idx] = match(input, tree[2 * tree_idx], tree[2 * tree_idx + 1]);
    }
}

void TournamentSort::sort(std::vector<int>& input) {
    std::vector<int> tree = build_tree(input);
    std::vector<int> result(input.size());
    for (int i = 0; i < input.size(); i++) {
        int min_idx = tree[1];
        result[i] = input[min_idx];
        input[min_idx] = INF;
        update_tree(input, tree, min_idx);
    }
    input = result;
}