#include<bits/stdc++.h>
#include<cctype>
using namespace std;
//TC - O(N) SC-O(N)
class Solution {
public:
    bool isPalindrome(string s) {
        string cp;
        string str;
        for(auto x:s){
            if(isalnum(x)){
                cp.push_back(tolower(x));
            }
        }
        str=cp;
        reverse(str.begin(),str.end());
        if(str==cp){
            return true;
        }
        else{
            return false;
        }
    }
};