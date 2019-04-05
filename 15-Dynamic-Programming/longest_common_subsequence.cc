#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <string>
#include <cassert>

using namespace std;

class LCS{
private:
    const int ninf = INT32_MIN;
    vector<vector<int>> c;
    vector<vector<int>> bt;
    int len_a;
    int len_b;
    string arr_a;
    string arr_b;
    // for bt
    const int eq = 1;
    const int st = 0;
    const int nd = 2;

public:
    LCS(string &a, string &b):arr_a(a),arr_b(b),len_a(a.size()), len_b(b.size()){
        for(int i = 0; i <= len_a; ++i){
            c.push_back(vector<int>(len_b+1, 0));
            bt.push_back(vector<int>(len_b+1, 0));
        }
    }

    int lcs_length(){
        for(int i = 1; i <= len_a; ++i){
            for(int j = 1; j <= len_b; ++j){
                if(arr_a[i-1] == arr_b[j-1]){
                    c[i][j] = c[i-1][j-1] + 1;
                    bt[i][j] = eq;
                }else if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                    bt[i][j] = st;
                }else{
                    c[i][j] = c[i][j-1];
                    bt[i][j] = nd;
                }
            }
        }
        return c[len_a][len_b];
    }

    string lcs(){
        int i = len_a, j = len_b;
        string rst = "";
        while(i != 0 || j != 0){
            if(bt[i][j] == eq){
                rst = arr_a[i-1]+rst;
                --i;
                --j;
            }else if(bt[i][j] == st){
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
    int len = sol.lcs_length();
    string rst = sol.lcs();
    assert(len == rst.size());
    cout << "length: " << len << ", lcs: " << rst << endl;
    return 0;
}