class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto it:operations){
            if(it=="D"){
                st.push(2*(st.top()));
            }
            else if(it=="C"){
                st.pop();
            }
            else if(it=="+"){
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.push(val1);
                st.push(val1+val2);
            }
            else{
                st.push(stoi(it));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};