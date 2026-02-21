//TC - O(N)  SC-O(1)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i,j;
        for(i=0,j=s.size()-1;i<j;i++,j--){
                char temp = s[i];
                s[i] = s[j];
                s[j] =  temp;
        }
    }
};