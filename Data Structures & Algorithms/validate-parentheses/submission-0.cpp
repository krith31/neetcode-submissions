class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char el:s){
            if(el=='[' || el=='(' || el=='{'){
                st.push(el);
            }
            else{
                if(st.empty()) return false;
                char ch=st.top();
                st.pop();
                if(el==')' && ch!='(') return false;
                if(el==']' && ch!='[') return false;
                if(el=='}' && ch!='{') return false;
            }
        }
        return st.empty();
    }
};
