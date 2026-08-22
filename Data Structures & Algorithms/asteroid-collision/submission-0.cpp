class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(auto it:asteroids){
            bool flag=false;
            while(!st.empty() && st.top()>0 && it<0){
                if(st.top()<-it){
                    st.pop();
                }
                else if(st.top()==-it){
                    st.pop();
                    flag=true;
                    break;
                }
                else{
                    flag=true;
                    break;
                }
            }
            if(!flag){
                st.push(it);
            }
        }
        vector<int> vec;
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        } 
        reverse(vec.begin(),vec.end());
        return vec;      

        

    }
};