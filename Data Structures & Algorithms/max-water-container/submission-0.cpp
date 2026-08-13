class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            int mini=min(heights[i],heights[j]);
            ans=max(ans,mini*(j-i));
            if(mini==heights[i]){
                i++;
            }
            else if(mini==heights[j]){
                j--;
            }
        }
        return ans;
    }
};
