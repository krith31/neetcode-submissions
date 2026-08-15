class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp1;
        for(int i=0;i<s1.size();i++){
            mp1[s1[i]]++;
        }
        int left=0;
        map<char,int> mp2;
        for(int right=0;right<s2.size();right++){
            mp2[s2[right]]++;
            if(right-left+1>s1.size()){
                mp2[s2[left]]--;
                if(mp2[s2[left]]==0){
                    mp2.erase(s2[left]);
                }
                left++;
            }
            if(right-left+1==s1.size()){
                if(mp1==mp2){
                    return true;
                }
            }
        }
        return false;
    }
};
