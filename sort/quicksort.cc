#include <iostream>
#include <vector>
#include <functional>
#include <stack>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
typedef chrono::milliseconds msec;
typedef chrono::steady_clock clk;


// int partition(vector<int> &nums, int l, int h)
// {
// 	int i = l + 1, j = h;
// 	int temp = nums[l];
// 	while (true)
// 	{
// 		while (nums[i] <= temp && i < h)
// 			i++;
// 		while (temp <= nums[j] && j > l)
// 			j--;
// 		if (i >= j)
// 			break;
// 		swap(nums[i], nums[j]);
// 	}
// 	swap(nums[l], nums[j]);
// 	return j;
// }

template<typename T>
int partition(vector<T> &arr, int p, int r){
    int i = p + 1, j = r;
    T pivot = arr.at(p);
    // int i = p-1;
    // for(int j = p; j < r; ++j){
    //     if(less<T>()(arr.at(j), arr.at(r))){
    //         std::swap(arr.at(++i), arr.at(j));
    //     }
    // }
    // std::swap(arr.at(++i), arr.at(r));
    // return i;

    while (true)
    {
        while (i < r && !less<T>()(pivot, arr.at(i)))  // use arr[] and <= to get better performance.
            i++;
        while (j > p && !less<T>()(arr.at(j), pivot))
            j--;
        if (i >= j)
            break;
        std::swap(arr.at(i), arr.at(j));
    }
    std::swap(arr.at(p), arr.at(j));
    return j;
}

template<typename T>
void quicksort(vector<T> &arr, int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
        // }
    }
}

template<typename T>
void quicksort2(vector<T> &arr, int p, int r){ // non-recursive
    stack<pair<int, int>, deque<pair<int, int>>> subseq;
    int q = partition(arr, p, r);
    // if q == r or q == p, subsequence will be the same as original sequence, 
    // this would cause dead loop. We need to handle this situation.
    // Update: it's unneccessary. Just don't use q again.

    if(p < q-1)
        subseq.push({p, q-1});
    if(q+1 < r)
        subseq.push({q+1, r});
    while(!subseq.empty()){
        auto p_r = subseq.top();
        subseq.pop();
        int p = p_r.first, r = p_r.second;
        // cout << p << ", " << q << endl;
        int q = partition(arr, p, r);
        if(p < q-1)
            subseq.push({p, q-1});
        if(q+1 < r)
            subseq.push({q+1, r});
        }
}

int main(){
    vector<int> arr, arr2, arr3;
    mt19937 rand_engine(random_device{}());
    int max = 10000000;
    for(int i = 0; i < max; ++i){
        // arr.push_back(uniform_int_distribution<int>{0, 1000000}(rand_engine));
        arr.push_back(uniform_int_distribution<int>{0, max/10}(rand_engine));
        // arr.push_back(i);
    }
    arr3 = arr2 = arr;
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
    sort(arr2.begin(), arr2.end());
    end = clk::now();
    ms = chrono::duration_cast<msec>(end-begin);
    cout << "Quicksort non-recursive. Total time: " << ms.count() << "ms." << endl;
    begin = clk::now();
    sort(arr3.begin(), arr3.end());
    end = clk::now();
    ms = chrono::duration_cast<msec>(end-begin);
    cout << "std::sort. Total time: " << ms.count() << "ms." << endl;
    // cout << "Sorted array: " << endl;
    // for(const auto &c : arr)
    //     cout << c << ", ";
    // cout << endl;
    return 0;
}