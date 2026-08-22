class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(const string& s:tokens) {
            if(s=="+" || s=="-" || s=="*" || s=="/") {
                long long val1=st.top(); 
                st.pop(); 
                long long val2=st.top(); 
                st.pop(); 

                if(s=="+") st.push(val2+val1);
                else if(s=="-") st.push(val2-val1);
                else if(s=="*") st.push(val2*val1);
                else if(s=="/") st.push(val2/val1);
            } else {
                st.push(stoll(s));
            }
        }
        return st.top();
    }
};
