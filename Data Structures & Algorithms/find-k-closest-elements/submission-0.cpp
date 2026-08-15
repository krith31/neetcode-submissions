class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0;
        int right=arr.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(arr[mid]<x){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        vector<int> ans;
        int l=left-1;
        int r=left;
        while(ans.size()<k){
            if(l<0){
                ans.push_back(arr[r++]);
            }
            else if(r>=arr.size()){
                ans.push_back(arr[l--]);
            }
            else if(abs(arr[l]-x)<=abs(arr[r]-x)){
                ans.push_back(arr[l--]);
            }
            else{
                ans.push_back(arr[r++]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};