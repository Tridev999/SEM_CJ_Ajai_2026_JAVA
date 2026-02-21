#include<bits/stdc++.h>
using namespace std;
//TC - O(N) SC-O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        if(pos!=string::npos){
            return pos;
        }
        else{
            return -1;
        }
    }
};