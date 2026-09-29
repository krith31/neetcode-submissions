class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        for(int i=0;i<26;i++){
            rank[order[i]-'a']=i;
        }

        for(int i=0;i<words.size()-1;i++){
            string word1=words[i];
            string word2=words[i+1];

            int j=0;
            while(j<word1.size() && j<word2.size() && word1[j]==word2[j]){
                j++;
            }

            if(j == word1.size()) {
                continue;
            }
            if(j == word2.size()) {
                return false;
            }
            else if(rank[word1[j]-'a']>rank[word2[j]-'a']){
                return false;
            }
        }
        return true;

    }
};