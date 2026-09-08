class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=nums[0];
        for(auto it:nums){
            if(sum<0){
                sum=0;
            }
            sum+=it;
            
            ans=max(ans,sum);
        }
        return ans;
    }
};
