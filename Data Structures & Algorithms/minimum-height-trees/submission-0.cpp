class Solution {
private:
    int dfs(int node, vector<vector<int>>& adj, int parent){
        int height=0;
        for(auto it:adj[node]){
            if(it!=parent){
                height=max(height,dfs(it,adj,node));
            }
        }
        return 1+height;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto& i:edges){
            int a=i[0];
            int b=i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> heights(n,0);
        int min_height=INT_MAX;
        for(int i=0;i<n;i++){
            heights[i]=dfs(i,adj,-1);
            min_height=min(min_height,heights[i]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(heights[i]==min_height){
                ans.push_back(i);
            }
        }
        return ans;
    }
};