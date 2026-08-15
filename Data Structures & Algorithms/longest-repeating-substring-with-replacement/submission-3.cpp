class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int n=s.size();
        int maxfreq=0;
        int ans=0;
        map<char,int> mp;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            int dist=right-left+1;
            maxfreq=max(maxfreq,mp[s[right]]);
            while((dist-maxfreq)>k){
                mp[s[left]]--;
                left++;
                
                dist=right-left+1;
            }
            ans=max(ans,dist);
        }
        return ans;
    }
};
