#include <iostream>
#include <string>
#include <map>

using namespace std;

map<pair<int,int>, string> table;

//this is longest subsequence, not substring.
string longestPalindrome(string s, int off, int p, int len){
    s = s.substr(p, len);
    off = off + p;
    string rst = "";
    auto table_rst = table.find(make_pair(off,len));
    if(table_rst != table.end()){
        // cout << s << ", " << table_rst->second << endl;
        return table_rst->second;
    }
    if(s.size() <= 1){
        rst = s;
        table[make_pair(off,s.size())] = rst;
    }
    else if(s.size() == 2){
        if(s[0] != s[1])
            rst = s.substr(0,1);
        else
            rst = s;
        table[make_pair(off,1)] = rst;
    }else{
        if(s[0] == s[s.size()-1]){
            string sub = longestPalindrome(s, off, 1,s.size()-2);
            table[make_pair(off,len)] = rst;
            rst = s[0] + sub + s[s.size()-1];
        }else{
            string subl = longestPalindrome(s, off, 0, s.size()-1);
            string subr = longestPalindrome(s, off, 1, s.size()-1);
            rst = subl.size() > subr.size() ? subl : subr;
            if(rst == subl){
                table[make_pair(off,len-1)] = rst;
            }else{
                table[make_pair(off+1,len-1)] = rst;
            }
        }
    }
    
    return rst;
}

int main(){
    // string s = "abcbcbsjduiffjdjefhfe";
    // string s = "babadada";
    string s = "abcda";
    string rst = longestPalindrome(s, 0, 0,s.size());
    cout << rst << endl;
}