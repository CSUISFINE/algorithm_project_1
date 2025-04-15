#include "sorting_algorithms.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include <functional>

using namespace std;
using namespace std::chrono;

vector<int> generateAscending(int size) {
    vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
    return data;
}

vector<int> generateDescending(int size) {
    vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = size - i;
    }
    return data;
}

vector<int> generateRandom(int size) {
    vector<int> data(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, size);
    for (int i = 0; i < size; i++) {
        data[i] = dis(gen);
    }
    return data;
}

vector<int> generatePartiallySorted(int size) {
    vector<int> data = generateAscending(size);
    random_device rd;
    mt19937 gen(rd());
    int numSwaps = size / 10; // 10%
    for (int i = 0; i < numSwaps; i++) {
        int idx1 = gen() % size;
        int idx2 = gen() % size;
        swap(data[idx1], data[idx2]);
    }
    return data;
}

struct SortAlgorithm {
    string name;
    function<void(vector<int>&)> sortFunc;
};

int main() {
    vector<int> inputSizes = {1000, 10000, 100000, 1000000};
    vector<string> dataTypes = {"ascending", "descending", "random", "partially sorted"};
    vector<SortAlgorithm> algorithms;
    
    algorithms.push_back({"MergeSort", [](vector<int>& arr) { MergeSort ms; ms.sort(arr, 0, arr.size() - 1); }});
    algorithms.push_back({"HeapSort",  [](vector<int>& arr) { HeapSort ms; ms.sort(arr); }});
    algorithms.push_back({"BubbleSort",   [](vector<int>& arr) { BubbleSort ms; ms.sort(arr); }});
    algorithms.push_back({"InsertionSort", [](vector<int>& arr) { InsertionSort ms; ms.sort(arr, 0, arr.size() - 1); }});
    algorithms.push_back({"SelectionSort", [](vector<int>& arr) { SelectionSort ms; ms.sort(arr); }});
    algorithms.push_back({"QuickSort", [](vector<int>& arr) { QuickSort ms; ms.sort(arr, 0, arr.size() - 1); }});
    algorithms.push_back({"LibrarySort",  [](vector<int>& arr) { LibrarySort ms; ms.sort(arr); }});
    algorithms.push_back({"TimSort",   [](vector<int>& arr) { TimSort ms; ms.sort(arr); }});
    algorithms.push_back({"CocktailShakerSort",  [](vector<int>& arr) { CocktailShakerSort ms; ms.sort(arr); }});
    algorithms.push_back({"CombSort",  [](vector<int>& arr) { CombSort ms; ms.sort(arr); }});
    algorithms.push_back({"TournamentSort",   [](vector<int>& arr) { TournamentSort ms; ms.sort(arr); }});
    algorithms.push_back({"IntroSort",   [](vector<int>& arr) { IntroSort ms; ms.sort(arr); }});
    
    for (int size : inputSizes) {
        cout << "Input size: " << size << "\n";
        for (const string& type : dataTypes) {
            vector<int> originalData;
            if (type == "ascending") {
                originalData = generateAscending(size);
            } else if (type == "descending") {
                originalData = generateDescending(size);
            } else if (type == "random") {
                originalData = generateRandom(size);
            } else if (type == "partially sorted") {
                originalData = generatePartiallySorted(size);
            }
            
            cout << "  Data type: " << type << "\n";
            
            for (const auto& algo : algorithms) {
                long long totalTime = 0;
                int numTrials = 10;
                bool allCorrect = true;
                for (int trial = 0; trial < numTrials; trial++) {
                    vector<int> testData = originalData;
                    auto start = high_resolution_clock::now();
                    algo.sortFunc(testData);
                    auto end = high_resolution_clock::now();
                    long long duration = duration_cast<microseconds>(end - start).count();
                    totalTime += duration;
                    if (!is_sorted(testData.begin(), testData.end()))
                        allCorrect = false;
                }
                long long avgTime = totalTime / numTrials;
                cout << "    " << algo.name << ": avg time = " 
                     << avgTime << " us, sorted correctly = " 
                     << (allCorrect ? "YES" : "NO") << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}
