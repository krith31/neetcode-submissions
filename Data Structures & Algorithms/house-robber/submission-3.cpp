class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int a=nums[0];
        int b=max(nums[0],nums[1]);
        vector<int> ans(nums.size());
        ans[0]=a;
        ans[1]=b;
        for(int i=2;i<nums.size();i++){
            ans[i]=max(a+nums[i],b);
            a=b;
            b=ans[i];
        }
        return ans[nums.size()-1];
    }
};
