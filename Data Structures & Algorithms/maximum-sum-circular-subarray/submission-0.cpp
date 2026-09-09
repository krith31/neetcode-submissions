class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalmax=nums[0];
        int globalmin=nums[0];
        int curmax=0;
        int curmin=0;
        int total=0;
        for(int& num:nums){
            curmax=max(curmax+num,num);
            curmin=min(curmin+num,num);
            total+=num;
            globalmax=max(globalmax,curmax);
            globalmin=min(globalmin,curmin);
        }
        if(globalmax<0){
            return globalmax;
        }
        return max(globalmax,total-globalmin);
    }
};