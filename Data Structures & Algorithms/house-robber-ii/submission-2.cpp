class Solution {
public:
    int func(vector<int>& nums){
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return nums[0];
        vector<int> skipfirst(n-1);
        vector<int> skiplast(n-1);

        for(int i=0;i<n-1;i++){
            skiplast[i]=nums[i];
            skipfirst[i]=nums[i+1];
        }

        int ans1=func(skiplast);
        int ans2=func(skipfirst);

        return max(ans1,ans2);
    }
};
