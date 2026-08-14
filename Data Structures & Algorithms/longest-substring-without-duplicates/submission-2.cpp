class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int len=0;
        int left=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]]>1){
                mp[s[left]]--;
                left++;
                len--;

            }
            len++;
            maxi=max(maxi,len);
        }
        return maxi;
    }
};
