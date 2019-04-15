#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

string bigNumber(const string &a, const string &b){
    vector<int> rst(a.size()+b.size(), 0);
    string n1, n2;
    reverse_copy(a.begin(), a.end(), back_inserter(n1));
    reverse_copy(b.begin(), b.end(), back_inserter(n2));
    string rsts = "";
    for(size_t i = 0; i < n1.size(); ++i){
        for(size_t j = 0; j < n2.size(); ++j){
            rst.at(i+j) += (n1.at(i)-'0')*(n2.at(j)-'0');
        }
    }
    for(size_t i = 0; i < rst.size(); ++i){
        if(rst.at(i) >= 10){
            rst.at(i+1) += rst.at(i)/10;
            rst.at(i) %= 10;
        }
    }
    int i = rst.size()-1;
    for(; i >= 0; --i){
        // cout << rst.at(i);
        if(rst.at(i) != 0)
            break;
    }
    for(; i >= 0; --i)
        rsts += to_string(rst.at(i));
    return rsts;
}

int main(){
    cout << "Input number n1 n2: " << endl;
    string n1, n2, rst;
    while(cin >> n1 >> n2){
        rst = bigNumber(n1,n2);
        cout << "Result is: " << rst << endl;
        cout << "Input number n1 n2: " << endl;
    }
    
}
