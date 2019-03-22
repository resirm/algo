#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>

using namespace std;

/*
 * Randomized-Select algorithm in ITA 9.2.
 */

class Random_pivot{
    private:
        static default_random_engine engine;
        static decltype(std::random_device{}()) init_eng(){ return std::random_device{}(); }
    public:
        int operator()(int min, int max){
            return uniform_int_distribution<int>{min, max}(engine);
        }
};
default_random_engine Random_pivot::engine{init_eng()};

template<typename T> int test(const vector<T> &A){
    for_each(A.begin(), A.end(), [](const T i)->void{ cout << i; });
}

template<typename T> int randomized_partition(vector<T> &A, int p, int r){
    int pivot = Random_pivot()(p, r);
    // pivot = Random_pivot()(p, r);
    // cout << "pivot: " << pivot << endl;
    auto i = A.begin()+p, p_iter = A.begin()+pivot, r_iter = A.begin()+r;
    iter_swap(r_iter, p_iter);
    for(auto j = i; j != r_iter+1; ++j){
        if(*j < *r_iter){
            iter_swap(j, i);
            ++i;
        }
        // cout << *j << " ";
    }
    // cout << endl;
    iter_swap(i, r_iter);
    return i-A.begin();
    // return pivot;
}

template<typename T> T randomized_select(vector<T> &A, int p, int r, int i){
    if(p == r){
        return A.at(p);
    }
    int q = randomized_partition(A, p, r);
    int k = q-p+1;
    if(i == k)
        return A.at(q);
    else if(i < k)
        return randomized_select(A, p, q-1, i);
    else
        return randomized_select(A, q+1, r, i-k);
}

int main(){
    vector<int> A{5,2,3,4,1,7,9,12,6};
    // iter_swap(A.begin(),A.begin()+2);
    // for(int i = 0; i < 10; ++i){
    //     cout << Random_pivot()(0,9) << endl;
    // }
    int beg = 0, end = A.end()-A.begin();
    // cout << end << endl;
    // randomized_partition(A,beg,end);
    for(int i = 0; i < end; ++i){
        cout << i << "th number: " << randomized_select(A, beg, end-1, i+1) << endl;
    }
    // int min1 = randomized_select(A, beg, end, 8);
    // cout << min1 << endl;
    // test(A);
    for_each(A.begin(), A.end(), [](const int &i)->void{ cout << i << " "; });
    return 0;
}