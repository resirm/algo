#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

class LMIS{
private:
    vector<int> b;
    vector<list<int>> c;
    int len_a;
    int len;
    string arr_a;
    int find(int n){
        int left = 1, right = len, mid = (left+right)/2;
        while(left <= right){
            if(n > b[mid])
                left = mid + 1;
            else if(n < b[mid])
                right = mid - 1;
            else
                return mid;
            mid = (left+right)/2;
        }
        return left;
    }
public:
    LMIS(string &a):arr_a(a),len_a(a.size()),len(0){
        b = vector<int>(len_a, -1);
        if(len_a == 0){
            cout << "Empty input!" << endl;
            return;
        }
        b[1] = arr_a[0];
        len = 1;
        for(int i = 0; i <= len_a; ++i){
            c.push_back(list<int>());
        }
        c[1].push_back(b[1]);
    }

    void lmis(){
        for(int i = 1; i < len_a; ++i){
            cout << arr_a[i] << ", " << b[1] << endl;
            if(arr_a[i] < b[1]){
                b[0] = arr_a[i];
                c[1].front() = b[0];
                cout << b[0] << endl;
            }else{
                int j = find(arr_a[i]);
                cout << j << endl;
                b[j] = arr_a[i];
                c[j] = c[j-1];
                c[j].push_back(b[j]);
                // cout << "push c[" << j << "]" << endl;
                if(j > len){
                    len += 1;
                }
            }
        }

    }

    // int lmis_memo(int n){
    //     if(n == 1)
    //         return b[n] = 1;
    //     if(b[n] > 0)
    //         return b[n];
    //     // if(b[i-1] != -1 && b[i-1] < arr_a[j]){
    //     //     b[i] = arr_a[j];
    //     //     return i;
    //     // }else if(b[i-1] != -1){
    //     //     int t = lmis_memo(i-1, arr_a[j]);
    //     //     if(t > 0)
    //     //         b[t] = std::min(b[t], int(arr_a[j]));
    //     // }else if(b[i-1] == -1){
    //     //     return lmis_memo(i-1, arr_a[j]);
    //     // }
    //     if(b[n-1] == -1){
            
    //     }
        
    //     int q = -1;
    //     for(int i = 1; i < n; ++i){
    //         q = std::max(q, lmis_memo(i));
    //     }
    //     if(arr_a[n-1])
    //     return q+1;
    // }

    void print_lmis(){
        for_each(c[len].begin(), c[len].end(), [](const auto &i){ cout << char(i) << ", "; });
    }
};

int main(){
    string a("ebcbdabefefefggjkjrtyff");
    LMIS sol(a);

    sol.lmis();
    sol.print_lmis();
    return 0;
}