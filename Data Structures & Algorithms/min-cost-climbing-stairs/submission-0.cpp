class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> min_cost(n+1,0);
        min_cost[0]=0;
        min_cost[1]=0;
        for(int i=2;i<=n;i++){
            min_cost[i]=min((min_cost[i-1]+cost[i-1]),(min_cost[i-2]+cost[i-2]));
        }
        return min_cost[n];
    }
};
