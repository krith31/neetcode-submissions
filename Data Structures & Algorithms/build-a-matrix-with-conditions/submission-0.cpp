class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& arr){
        vector<vector<int>> adj(k+1);
        vector<int> indegree(k+1,0);
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            int u=arr[i][0];
            int v=arr[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==k){
            return ans;
        }
        return {};

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row_arr=topoSort(k,rowConditions);
        vector<int> col_arr=topoSort(k,colConditions);
        if(row_arr.empty() || col_arr.empty()) return {};
        vector<int> row_pos(k+1),col_pos(k+1);
        for(int i=0;i<k;i++){
            row_pos[row_arr[i]]=i;
            col_pos[col_arr[i]]=i;
        }
        vector<vector<int>> res(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            res[row_pos[i]][col_pos[i]]=i;
        }
        return res;
    }
};