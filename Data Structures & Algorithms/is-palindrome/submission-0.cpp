class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.size();
        int i=0;
        int j=len-1;
        while(i<j){
            while (i<j &&!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))){
                i++;
            }
            while(i<j &&!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))){
                j--;
            }
            char a=s[i];
            char b=s[j];

            if (a>='A'&& a<='Z')
                a=a+('a'-'A');

            if (b>='A' && b<='Z')
                b=b+('a'-'A');

            if (a!=b)
                return false;
            i++;
            j--;
            
        }
        return true;
    }
};
