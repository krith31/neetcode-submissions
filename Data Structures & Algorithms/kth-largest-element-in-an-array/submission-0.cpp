class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(int num:nums){
            maxHeap.push(num);
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans=maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};
