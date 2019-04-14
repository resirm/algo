#include <iostream>
#include <vector>
#include <functional>

#define parent(x) (x-1)/2
#define left(x) 2*x+1
#define right(x) 2*x+2

using namespace std;

template<typename T>
class Heap{
public:
    size_t size;
    size_t len;
    vector<T> heap;
    Heap() = default;
    Heap(const vector<T> &arr):heap(arr), size(arr.size()), len(arr.size()){ 
        cout << "Heap size: " << size << endl;
    }
    void max_heapify(size_t i){
        while(i < size){
            size_t max = i;
            if(left(i) < size && less<T>()(heap.at(i), heap.at(left(i))))
                max = left(i);
            if(right(i) < size && less<T>()(heap.at(max), heap.at(right(i))))
                max = right(i);
            if(i == max)
                return;
            swap(heap.at(i), heap.at(max));
            i = max;
        }
    }

    void build_heap(){
        for(int i = size/2-1; i >= 0; --i){ // if i is type size_t, it will be a dead loop!
            max_heapify(i);
        }
        // for(const auto &c : heap)
        //     cout << c << ", ";
        // cout << endl;
    }

    void heap_sort(){
        build_heap();
        cout << "build finished." << endl;
        while(size > 0){
            swap(heap.at(0), heap.at(size-1));
            --size;
            max_heapify(0);
            cout << "iteration " << len-size << endl;
            for(const auto &c : heap)
                cout << c << ", ";
            cout << endl;
        }
        size = len;
    }
};


int main(){
    vector<int> arr{1,5,2,6,14,3,66,23,43,26,74,21,17};
    Heap<int> h(arr);
    cout << "Input array: " << endl;
    for(const auto &c : arr)
        cout << c << ", ";
    cout << endl;
    h.heap_sort();
    cout << "Sorted array: " << endl;
    for(const auto &c : h.heap)
        cout << c << ", ";
    cout << endl;
    return 0;
}
