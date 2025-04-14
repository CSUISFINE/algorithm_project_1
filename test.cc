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

// 입력 데이터를 생성하는 함수들

// 오름차순 데이터 생성
vector<int> generateAscending(int size) {
    vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = i;  // 0, 1, 2, ... 순서대로
    }
    return data;
}

// 내림차순 데이터 생성
vector<int> generateDescending(int size) {
    vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = size - i;  // size, size-1, ... 1
    }
    return data;
}

// 무작위 데이터 생성
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

// 부분 정렬 데이터 생성: 오름차순 정렬을 기본으로 하되, 약 10%의 원소를 랜덤하게 섞음
vector<int> generatePartiallySorted(int size) {
    vector<int> data = generateAscending(size);
    random_device rd;
    mt19937 gen(rd());
    int numSwaps = size / 10; // 10% 정도의 교환 횟수
    for (int i = 0; i < numSwaps; i++) {
        int idx1 = gen() % size;
        int idx2 = gen() % size;
        swap(data[idx1], data[idx2]);
    }
    return data;
}

// 정렬 알고리즘을 래핑할 구조체
struct SortAlgorithm {
    string name;
    // 실제 정렬 알고리즘 함수: vector<int>&를 받아 정렬 수행
    function<void(vector<int>&)> sortFunc;
};

int main() {
    // 테스트할 입력 크기들
    vector<int> inputSizes = {1000, 10000, 100000, 1000000};
    // 테스트할 입력 유형들
    vector<string> dataTypes = {"ascending", "descending", "random", "partially sorted"};
    vector<SortAlgorithm> algorithms;
    
    // 정렬 알고리즘 목록 (예시로 std::sort를 사용)
    // 실제로는 여러분이 구현한 정렬 알고리즘을 여기에 등록하면 됩니다.
    
    algorithms.push_back({"MergeSort", [](vector<int>& arr) { MergeSort ms; ms.sort(arr, 0, arr.size() - 1); }});
    algorithms.push_back({"TimSort",   [](vector<int>& arr) { TimSort ms; ms.sort(arr); }});
    algorithms.push_back({"HeapSort",  [](vector<int>& arr) { HeapSort ms; ms.sort(arr); }});
    // 예: algorithms.push_back({"QuickSort",  quickSortFunction});

    // 테스트 실행
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
            
            // 각 알고리즘별 10회 실행하여 평균 실행시간 측정
            for (const auto& algo : algorithms) {
                long long totalTime = 0;
                int numTrials = 10;
                bool allCorrect = true;
                for (int trial = 0; trial < numTrials; trial++) {
                    // 원본 배열은 복사본을 이용하여 정렬 수행
                    vector<int> testData = originalData;
                    auto start = high_resolution_clock::now();
                    algo.sortFunc(testData);
                    auto end = high_resolution_clock::now();
                    long long duration = duration_cast<microseconds>(end - start).count();
                    totalTime += duration;
                    // 정렬 결과가 올바른지 확인 (오름차순 정렬되어야 함)
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
