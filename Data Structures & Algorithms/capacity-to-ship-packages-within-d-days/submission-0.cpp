class Solution {
public:
    int func(vector<int>& arr, int val){
        int sum=0;
        int day=1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>val){
                day++;
                sum=arr[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        int ans=0;
        for(auto it:weights){
            high+=it;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int days_count=func(weights,mid);
            
            if(days_count>days){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};