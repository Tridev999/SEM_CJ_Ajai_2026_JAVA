class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(char c : s) {
        if(isalnum(c)) {   
            result += tolower(c);
        }
        }
        int l = 0;
        int h = result.size()-1;

        while(l<h){
            if(result[l]!=result[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
};