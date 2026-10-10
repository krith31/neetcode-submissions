class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> arr(26,-1);
        int ans=-1;
        for(int i=0;i<s.size();i++){
            int id=s[i]-'a';
            if(arr[id]==-1){
                arr[id]=i;
            }
            else{
                ans=max(ans,i-arr[id]-1);
            }
        }
        return ans;
    }
};