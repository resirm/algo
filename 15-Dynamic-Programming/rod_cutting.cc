#include <iostream>
#include <vector>
#include <chrono>
#include <limits>
#include <algorithm>

class Rod_cutting{
private:
    std::vector<int> price_table;
    std::vector<int> memo;
    std::vector<int> revenue;
    std::vector<int> struc;
public:
    Rod_cutting(){
        price_table = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
        memo = std::vector<int>(11,INT32_MIN);
        struc = revenue = std::vector<int>(11,0);
    }
    int cut_rod(int n){
        if(n == 0)
            return 0;
        int q = INT32_MIN;
        for(int i = 1; i <= n; ++i){
            q = std::max(q, price_table[i-1]+cut_rod(n-i));
        }
        return q;
    }

    int cut_rod_memo(int n){
        if(memo[n] >= 0)
            return memo[n];
        int q = 0;
        for(int i = 1; i <= n; ++i){
            q = std::max(q, price_table[i-1]+cut_rod_memo(n-i));
        }
        memo[n] = q;
        return q;
    }

    int cut_rod_bottom_up(int n){
        for(int i = 1; i <= n; ++i){
            int q = INT32_MIN;
            for(int j = 1; j <= i; ++j){
                // q = std::max(q, price_table[j-1]+revenue[i-j]);
                if(q < price_table[j-1]+revenue[i-j]){
                    q = price_table[j-1]+revenue[i-j];
                    struc[i] = j;
                }
            }
            // std::cout << q << std::endl;
            revenue[i] = q;
        }
        return revenue[n];
    }

    void print_s(){
        // std::cout << "Optimal cut: " << std::endl;
        // for(int i = 1; i <= 10; ++i){
        //     std::cout << struc[i] << ", ";
        // }
        // std::cout << std::endl;
        // std::cout << "Optimal revenue for each subproblem: " << std::endl;
        // for(int i = 1; i <= 10; ++i){
        //     std::cout << revenue[i] << ", ";
        // }
        // std::cout << std::endl;
        for(int i = 1; i <= 10; ++i)
            print_s(i);
    }

    void print_s(int n){
        std::cout << "Optimal cut for length " << n << ": " << std::endl;
        int n_ = n;
        while(n > 0){
            std::cout << struc[n] << ", ";
            n -= struc[n];
        }
        std::cout << std::endl;
        std::cout << "Optimal revenue for length " << n_ << ": " << std::endl;
        std::cout << revenue[n_] << std::endl;
    }
};

// 15.1-5
int Fibonacci(int n){
    std::vector<int> Fib(n+1, 0);
    Fib[1] = 1;
    for(int i = 2; i <= n; ++i){
        Fib[i] = Fib[i-1] + Fib[i-2];
    }
    return Fib[n];
}

int main(){
    // typedef std::chrono::steady_clock steady_clock;
    // Rod_cutting Rod;
    // steady_clock::time_point start = steady_clock::now();
    // int max_rev = Rod.cut_rod(10);
    // steady_clock::time_point end = steady_clock::now();
    // std::chrono::nanoseconds dur = end - start;
    // std::cout << "Max revenue: " << max_rev << ", cut_rod() time spent: " << dur.count() << std::endl;
    // start = steady_clock::now();
    // max_rev = Rod.cut_rod_memo(10);
    // end = steady_clock::now();
    // dur = end - start;
    // std::cout << "Max revenue: " << max_rev << ", cut_rod_memo() time spent: " << dur.count() << std::endl;
    // start = steady_clock::now();
    // max_rev = Rod.cut_rod_bottom_up(10);
    // end = steady_clock::now();
    // dur = end - start;
    // std::cout << "Max revenue: " << max_rev << ", cut_rod_memo_bottom_up() time spent: " << dur.count() << std::endl;
    // Rod.print_s();

    int n = 10;
    while(n-- > 0)
        std::cout << Fibonacci(10-n) << std::endl;
    return 0;
}