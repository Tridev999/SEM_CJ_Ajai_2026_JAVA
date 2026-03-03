class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int min=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<min){
                min=prices[i];
            }
            else{
                profit=max(profit,prices[i]-min);
            }
        }
        return profit;
    }
};