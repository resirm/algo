#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template<typename T>
void bubble_sort(vector<T> &arr){
    if(arr.empty())
        return;
    for(size_t i = arr.size(); i > 0; --i){
        for(size_t j = 1; j < i; ++j){
            if(less<T>()(arr.at(j), arr.at(j-1))){
                swap(arr.at(j), arr.at(j-1));
            }
        }
    }
}

int main(){
    vector<int> arr{1,5,2,6,14,3,66,23,43,26,74,21,17};
    cout << "Input array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    bubble_sort(arr);
    cout << "Sorted array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    return 0;
}
