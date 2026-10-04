class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(abs(target)>sum) return 0;
        int offset=sum;
        vector<vector<int>> dp(n+1,vector<int> ((2*sum)+1,0));
        dp[0][0 + offset] = 1;
        for(int i=1;i<=n;i++){
            int current_num=nums[i-1];
            for(int s=0;s<=2*sum;s++){
                if(dp[i-1][s]>0){
                    dp[i][s+current_num]+=dp[i-1][s];
                    dp[i][s-current_num]+=dp[i-1][s];
                }
                
            }
        }
        return dp[n][target+offset];
    }
};