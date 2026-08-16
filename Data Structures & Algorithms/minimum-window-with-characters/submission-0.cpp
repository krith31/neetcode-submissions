class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        vector<int> freq(128,0);
        int count=t.size();
        int left=0;
        int right=0, minlen=INT_MAX, startindex=0;
        for(char c:t){
            freq[c]++;
        }

        while(right<s.size()){
            char current=s[right];
            if(freq[current]>0){
                count--;
            }
            freq[current]--;
            right++;
            while(count==0){
                int currentLength = right - left;
                if (currentLength < minlen) {
                    minlen = currentLength;
                    startindex = left;
                }
                char removed = s[left];
                freq[removed]++;
                if (freq[removed] > 0) {
                    count++;
                }
                left++;
            }
        }
        if (minlen == INT_MAX) {
            return "";
        }

        return s.substr(startindex, minlen);
    }
};
