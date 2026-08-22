class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> vec(n,0);
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                int prev=st.top();
                st.pop();
                vec[prev]=i-prev;
            }
            st.push(i);
        }
        return vec;
    }
};
