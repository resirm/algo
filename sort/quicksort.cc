#include <iostream>
#include <vector>
#include <functional>
#include <stack>

using  namespace std;

template<typename T>
size_t partition(vector<T> &arr, size_t p, size_t r){
    size_t i = p-1;
    for(int j = p; j < r; ++j){
        if(less<T>()(arr.at(j), arr.at(r))){
            std::swap(arr.at(++i), arr.at(j));
        }
    }
    std::swap(arr.at(++i), arr.at(r));
    return i;
}

template<typename T>
void quicksort(vector<T> &arr, size_t p, size_t r){
    if(p < r){
        size_t q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q, r);
    }
}

template<typename T>
void quicksort2(vector<T> &arr, size_t p, size_t r){ // non-recursive
    stack<pair<size_t, size_t>> subseq;
    size_t q = partition(arr, p, r);
    if(p < q-1)
        subseq.push({p, q-1});
    if(q < r)
        subseq.push({q, r});
    while(!subseq.empty()){
        auto p_r = subseq.top();
        subseq.pop();
        size_t p = p_r.first, r = p_r.second;
        size_t q = partition(arr, p, r);
        if(p < q-1)
            subseq.push({p, q-1});
        if(q < r)
            subseq.push({q, r});
    }
}

int main(){
    vector<int> arr{1,5,2,6,14,3,66,23,43,26,74,21,17};
    cout << "Input array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    quicksort2(arr, 0, arr.size()-1);
    cout << "Sorted array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    return 0;
}