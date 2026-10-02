class Solution {
public:
    int climbStairs(int n) {
        int prev1=0;
        int prev2=1;
        int prev3=2;
        if(n<=2) return n;
        for(int i=3;i<=n;i++){
            int current=prev2+prev3;
            prev1=prev2;
            prev2=prev3;
            prev3=current;
        }
        return prev3;
    }
};
