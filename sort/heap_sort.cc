#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <chrono>

#define parent(x) (x-1)/2
#define left(x) 2*x+1
#define right(x) 2*x+2

using namespace std;
typedef chrono::milliseconds msec;
typedef chrono::steady_clock clk;

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
    }

    void heap_sort(){
        build_heap();
        // cout << "build finished." << endl;
        while(size > 1){
            swap(heap.at(0), heap.at(size-1));
            --size;
            max_heapify(0);
            // cout << "iteration " << len-size << endl;
            // for(const auto &c : heap)
            //     cout << c << ", ";
            // cout << endl;
        }
        size = len;
    }
};


int main(){
    // vector<int> arr{1,5,2,6,14,3,66,23,43,26,74,21,17};
    vector<int> arr, arr2;
    mt19937 rand_engine(random_device{}());
    for(int i = 0; i < 10000000; ++i){
        arr.push_back(uniform_int_distribution<int>{0, 1000000}(rand_engine));
    }
    Heap<int> h(arr);
    // cout << "Input array: " << endl;
    // for(const auto &c : arr)
    //     cout << c << ", ";
    // cout << endl;
    chrono::steady_clock::time_point begin = clk::now();
    h.heap_sort();
    chrono::steady_clock::time_point end = clk::now();
    auto ms = chrono::duration_cast<msec>(end-begin);
    cout << "Heapsort. Total time: " << ms.count() << "ms." << endl;
    // cout << "Sorted array: " << endl;
    // for(const auto &c : h.heap)
    //     cout << c << ", ";
    // cout << endl;
    return 0;
}
