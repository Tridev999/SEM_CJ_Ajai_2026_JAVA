class Solution {
    public:
        int reverse(int x) {
            long long rev=0,digit;
    
            while(x!=0){
                digit=x%10;
                rev=rev*10+digit;
                x/=10;
            }
            if(rev<INT_MIN || rev>INT_MAX)
            return 0;
            else return (int) rev;
            
        }
    };