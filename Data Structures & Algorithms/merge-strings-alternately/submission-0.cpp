class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int len1=word1.size();
        int len2=word2.size();
        int mini=min(len1,len2);
        for(int i=0;i<mini;i++){
            s=s+word1[i];
            s=s+word2[i];
        }
        if(mini==len1){
            for(int i=mini;i<len2;i++){
                s=s+word2[i];
            }
        }
        else{
            for(int i=mini;i<len1;i++){
                s=s+word1[i];
            }
        }
        return s;
    }
};