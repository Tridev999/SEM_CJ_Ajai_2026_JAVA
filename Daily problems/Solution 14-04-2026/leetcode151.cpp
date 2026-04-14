#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
    string str;
    string st;
    stringstream ss(s);
    vector<string> vec;
    while(ss >> str){
        vec.push_back(str);
    }
    for(int i=vec.size()-1;i>=0;i--){
        st=st+vec[i];
        if(i!=0){
            st=st+" ";
        }
    
    }
       return st; 
    }
};