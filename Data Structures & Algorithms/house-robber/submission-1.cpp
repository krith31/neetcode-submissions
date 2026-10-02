class Solution {
public:
    int rob(vector<int>& nums) {
        int rob=0;
        int norob=0;
        for(int i=0;i<nums.size();i++){
            int newrob=norob+nums[i];
            int newNorob=max(norob,rob);
            rob=newrob;
            norob=newNorob;
        }
        return max(rob,norob);
    }
};
