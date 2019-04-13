#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void selection_sort(vector<T> &arr){
    if(arr.empty())
        return;
    for(size_t i = arr.size(); i > 0; --i){
        size_t max_ind = i-1;
        for(size_t j = 0; j < i; ++j){
            if(less<T>()(arr.at(max_ind), arr.at(j)))
                max_ind = j;
        }
        swap(arr.at(max_ind), arr.at(i-1));
    }
}

int main(){
    vector<int> arr{1,5,2,6,14,3,66,23,43,26,74,21,17};
    cout << "Input array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    selection_sort(arr);
    cout << "Sorted array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    return 0;
}
