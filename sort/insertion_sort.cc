#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename T>
void insertion_sort(vector<T> &arr){
    if(arr.empty())
        return;
    for(size_t i = 1; i < arr.size(); ++i){
        T key = arr.at(i);
        size_t j = i-1;
        while(j >= 0 && less<T>()(arr.at(j), key)){
            arr.at(j+1) = arr.at(j);
            j -= 1;
        }
        arr.at(j+1) = key;
    }
}

int main(){
    vector<int> arr{1,5,2,6,14,3,66,23,43,26,74,21,17};
    cout << "Input array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    insertion_sort(arr);
    cout << "Sorted array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    return 0;
}