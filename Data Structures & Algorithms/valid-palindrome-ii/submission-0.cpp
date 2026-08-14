class Solution {
public:
    bool func(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return func(s,i+1,j) || func(s,i,j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};