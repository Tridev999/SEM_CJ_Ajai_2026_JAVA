class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        vector<int>result(nums.size(),0);

        for(int i=0;i<nums.size();i++){
            result[i]=prefix;
        prefix*=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            result[i]*=suffix;
        suffix*=nums[i];
        }
        return result;

    }
};