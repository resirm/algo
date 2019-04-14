#include <iostream>
#include <vector>
#include <functional>
#include <stack>
#include <random>
#include <chrono>

using namespace std;
typedef chrono::milliseconds msec;
typedef chrono::steady_clock clk;

template<typename T>
int partition(vector<T> &arr, int p, int r){
    int i = p-1;
    for(int j = p; j < r; ++j){
        if(less<T>()(arr.at(j), arr.at(r))){
            std::swap(arr.at(++i), arr.at(j));
        }
    }
    std::swap(arr.at(++i), arr.at(r));
    return i;
}

template<typename T>
void quicksort(vector<T> &arr, int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        if(q == r){
            if(p < r)
                quicksort(arr, p, q-1);
        }else if(q == p){
            if(p < r)
                quicksort(arr, p+1, r);
        }else{
            quicksort(arr, p, q-1);
            quicksort(arr, q, r);
        }
    }
}

template<typename T>
void quicksort2(vector<T> &arr, int p, int r){ // non-recursive
    stack<pair<int, int>> subseq;
    int q = partition(arr, p, r);
    // if q == r or q == p, subsequence will be the same as original sequence, 
    // this would cause dead loop. We need to handle this situation.
    if(q == r){
        if(p < r)
            subseq.push({p, q-1});
    }else if(q == p){
        if(p < r)
            subseq.push({p+1, r});
    }else{
        if(p < q-1)
            subseq.push({p, q-1});
        if(q < r)
            subseq.push({q, r});
    }
    while(!subseq.empty()){
        auto p_r = subseq.top();
        subseq.pop();
        int p = p_r.first, r = p_r.second;
        // cout << p << ", " << q << endl;
        int q = partition(arr, p, r);
        if(q == r){
            if(p < r)
                subseq.push({p, r-1});
        }else if(q == p){
            if(q < r)
                subseq.push({p+1, r});
        }else{
            if(p < q-1)
                subseq.push({p, q-1});
            if(q < r)
                subseq.push({q, r});
        }
    }
}

int main(){
    vector<int> arr, arr2;
    mt19937 rand_engine(random_device{}());
    for(int i = 0; i < 10000000; ++i){
        arr.push_back(uniform_int_distribution<int>{0, 1000000}(rand_engine));
    }
    arr2 = arr;
    // vector<int> arr{1,5,2,6,14,3,66,23,43,26,74,21,17};
    // cout << "Input array: " << endl;
    // for(const auto &c : arr)
    //     cout << c << ", ";
    // cout << endl;
    chrono::steady_clock::time_point begin = clk::now();
    quicksort(arr, 0, arr.size()-1);
    chrono::steady_clock::time_point end = clk::now();
    auto ms = chrono::duration_cast<msec>(end-begin);
    cout << "Quicksort recursive. Total time: " << ms.count() << "ms." << endl;
    begin = clk::now();
    quicksort2(arr2, 0, arr2.size()-1);
    end = clk::now();
    ms = chrono::duration_cast<msec>(end-begin);
    cout << "Quicksort non-recursive. Total time: " << ms.count() << "ms." << endl;
    // cout << "Sorted array: " << endl;
    // for(const auto &c : arr)
    //     cout << c << ", ";
    // cout << endl;
    return 0;
}