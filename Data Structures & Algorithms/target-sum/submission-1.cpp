class Solution {
    map<pair<int,int>,int> mp;
private:
    int calculateSum(vector<int>& nums, int target, int index, int current_sum){
        if(index==nums.size()){
            if(current_sum==target) return 1;
            else return 0;
        }
        if(mp.count({index,current_sum})){
            return mp[{index,current_sum}];
        }
        int add=calculateSum(nums, target, index+1, current_sum+nums[index]);
        int subtract=calculateSum(nums,target, index+1, current_sum-nums[index]);

        return mp[{index,current_sum}]=add+subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return calculateSum(nums, target, 0,0);
    }
};