#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
typedef chrono::milliseconds msec;
typedef chrono::steady_clock clk;

template <typename T>
void coungting_sort(vector<T> &arr, vector<T> &sorted, int k){ // k is the number of possible value
    vector<T> cnt(k, 0);
    for(int i = 0; i < arr.size(); ++i){
        ++cnt[arr[i]];
    }
    for(int i = 1; i < k; ++i){
        cnt[i] += cnt[i-1];
    }
    for(int i = arr.size()-1; i >= 0; --i){
        sorted[cnt[arr[i]]] = arr[i];
        --cnt[arr[i]];
    }
}

int main(){
    int max = 10000000;
    int k = 100;
    vector<int> arr, arr2, sorted(max, 0);
    mt19937 rand_engine(random_device{}());
    for(int i = 0; i < max; ++i){
        arr.push_back(uniform_int_distribution<int>{0, k-1}(rand_engine));
    }
    arr2 = arr;
    // cout << "Input array: " << endl;
    // for(const auto &c : arr)
    //     cout << c << ", ";
    // cout << endl;
    chrono::steady_clock::time_point begin = clk::now();
    coungting_sort(arr, sorted, k);
    chrono::steady_clock::time_point end = clk::now();
    auto ms = chrono::duration_cast<msec>(end-begin);
    cout << "Counting sort. Total time: " << ms.count() << "ms." << endl;
    begin = clk::now();
    sort(arr2.begin(), arr2.end());
    end = clk::now();
    ms = chrono::duration_cast<msec>(end-begin);
    cout << "std::sort. Total time: " << ms.count() << "ms." << endl;
    // cout << "Sorted array: " << endl;
    // for(const auto &c : arr2)
    //     cout << c << ", ";
    // cout << endl;
    return 0;
}