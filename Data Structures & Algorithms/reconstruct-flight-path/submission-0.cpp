class Solution {
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    vector<string> ans;

    void dfs(string s){
        while(!adj[s].empty()){
            string next=adj[s].top();
            adj[s].pop();

            dfs(next);
        }
        ans.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(const auto& s:tickets){
            adj[s[0]].push(s[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
