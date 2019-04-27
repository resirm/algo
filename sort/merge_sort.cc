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
void merge(vector<T> &arr, int p, int q, int r){
    vector<T> left(arr.begin()+p, arr.begin()+q+1);
    vector<T> right(arr.begin()+q+1, arr.begin()+r+1);

    for(auto i = 0, j = 0, k = p; k <= r; ++k){
        if(i < left.size() && j < right.size()){
            if(less<T>()(right[j], left[i])){
                arr[k] = right[j++];
            }else{
                arr[k] = left[i++];
            }
        }
        else if(i == left.size() && j < right.size())
            arr[k] = right[j++];
        else if(i < left.size() && j == right.size())
            arr[k] = left[i++];
        else
            break; // i == left.size() && j == right.size()
    }
}

template <typename T>
void merge_sort(vector<T> &arr, int p, int r){
    if(p >= r)
        return;
    int q = (p+r)/2;
    merge_sort(arr, p, q);
    merge_sort(arr, q+1, r);
    merge(arr, p, q, r);
}

int main(){
    vector<int> arr, arr2;
    mt19937 rand_engine(random_device{}());
    int max = 10000000;
    for(int i = 0; i < max; ++i){
        // arr.push_back(uniform_int_distribution<int>{0, 1000000}(rand_engine));
        arr.push_back(uniform_int_distribution<int>{0, max/10}(rand_engine));
        // arr.push_back(i);
    }
    arr2 = arr;
    chrono::steady_clock::time_point begin = clk::now();
    merge_sort(arr, 0, arr.size()-1);
    chrono::steady_clock::time_point end = clk::now();
    auto ms = chrono::duration_cast<msec>(end-begin);
    cout << "Mergesort recursive. Total time: " << ms.count() << "ms." << endl;

    begin = clk::now();
    sort(arr2.begin(), arr2.end());
    end = clk::now();
    ms = chrono::duration_cast<msec>(end-begin);
    cout << "std::sort. Total time: " << ms.count() << "ms." << endl;
    // cout << "Sorted array: " << endl;
    // for(const auto &c : arr)
    //     cout << c << ", ";
    // cout << endl;
    return 0;
}