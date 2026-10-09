class Solution {
    int mod=1e9+7;
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned int>> dp(n,vector<unsigned int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            dp[0][t]=(t%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                unsigned int notpick=dp[i-1][t];
                unsigned int pick=0;
                if(coins[i]<=t) pick=dp[i][t-coins[i]];
                dp[i][t]=pick+notpick;
            }
        }
        return (int)dp[n-1][amount];
    }
};