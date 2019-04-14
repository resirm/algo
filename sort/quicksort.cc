#include <iostream>
#include <vector>
#include <functional>

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

int main(){
    vector<int> arr{1,5,2,6,14,3,66,23,43,26,74,21,17};
    cout << "Input array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    quicksort(arr, 0, arr.size()-1);
    cout << "Sorted array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    return 0;
}