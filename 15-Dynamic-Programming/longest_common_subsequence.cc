#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class LCS{
private:
    vector<vector<int>> c;
    int len_a;
    int len_b;
    string arr_a;
    string arr_b;

public:
    LCS(string &a, string &b):arr_a(a),arr_b(b),len_a(a.size()), len_b(b.size()){
        for(int i = 0; i <= len_a; ++i){
            c.push_back(vector<int>(len_b+1, -1));
            c[i][0] = 0;
            c[0][i] = 0;
        }
    }

    void lcs(){
        for(int i = 1; i <= len_a; ++i){
            for(int j = 1; j <= len_b; ++j){
                if(arr_a[i-1] == arr_b[j-1]){
                    c[i][j] = c[i-1][j-1] + 1;
                }else if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                }else{
                    c[i][j] = c[i][j-1];
                }
            }
        }
        // debug: print table c.
        // for(int i = 0; i <= len_a; ++i){
        //     for(int j = 0; j <= len_b; ++j)
        //         cout << c[i][j] << ", ";
        //     cout << endl;
        // }
    }

    int lcs_memo(int i, int j){
        if(i == 0 || j == 0)
            return 0;
        if(c[i][j] >= 0)
            return c[i][j];
        if(arr_a[i-1] == arr_b[j-1])
            return c[i][j] = lcs_memo(i-1, j-1)+1;
        else
            return c[i][j] = std::max(lcs_memo(i-1, j), lcs_memo(i, j-1));
    }

    string print_lcs(){
        cout << "print: " << endl;
        int i = len_a, j = len_b;
        string rst = "";
        while(i != 0 && j != 0){
            if(arr_a[i-1] == arr_b[j-1]){
                rst = arr_a[i-1]+rst;
                --i;
                --j;
            }else if(c[i-1][j] >= c[i][j-1]){
                --i;
            }else{
                --j;
            }
        }
        return rst;
    }
};

int main(){
    string a("abcbdabefefefff"), b("bdcabaffeff");
    LCS sol(a,b);
    // sol.lcs();
    sol.lcs_memo(a.size(), b.size());
    string rst = sol.print_lcs();
    cout << "length: " << rst.size() << ", lcs: " << rst << endl;
    return 0;
}