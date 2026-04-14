class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>v;
       
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                v.push_back(tolower(s[i]));
            }
        }
        vector<char>v1=v;
        reverse(v1.begin(),v1.end());
        for(int i=0;i<v.size();i++){
            if(v[i]!=v1[i]){
                return false;
            }
        }
return true ;
    }
};