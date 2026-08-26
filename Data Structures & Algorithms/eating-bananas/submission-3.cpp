class Solution {
public:
    long long func(vector<int>& piles, int mid){
        long long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=((piles[i]-1)/mid)+1;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int maxi=0;
        for(auto it:piles){
            maxi=max(maxi,it);
        }
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long total_time=func(piles,mid);
            if(total_time<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
