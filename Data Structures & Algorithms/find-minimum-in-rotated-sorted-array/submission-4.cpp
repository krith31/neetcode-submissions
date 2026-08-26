class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int min_val=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            min_val=min(nums[mid],min_val);

            if(nums[mid]>=nums[left] && nums[left]>=nums[right]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return min_val;
    }
};
