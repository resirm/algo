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

template<typename T> int randomized_partition(vector<T> &A, int p, int r){
    int pivot = Random_pivot()(p, r);
    auto i = A.begin()+p, p_iter = A.begin()+pivot, r_iter = A.begin()+r;
    iter_swap(r_iter, p_iter);
    for(auto j = i; j != r_iter+1; ++j){
        if(less<T>()(*j, *r_iter)){
            iter_swap(j, i);
            ++i;
        }
    }
    iter_swap(i, r_iter);
    return i-A.begin();
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
    vector<float> A{5.4,2,3,4.22,1,7,9.6,12,6};
    int beg = 0, end = A.end()-A.begin();
    for(int i = 0; i < end; ++i){
        cout << i+1 << "th number: " << randomized_select(A, beg, end-1, i+1) << endl;
    }
    for_each(A.begin(), A.end(), [](const int &i)->void{ cout << i << " "; });
    return 0;
}