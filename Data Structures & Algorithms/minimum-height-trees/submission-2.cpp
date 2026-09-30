class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(const auto& i:edges){
            int a=i[0];
            int b=i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        int rem=n;
        while(rem>2){
            int count=q.size();
            rem-=count;
            for(int i=0;i<count;i++){
                int node=q.front();
                q.pop();
                for(int ne:adj[node]){
                    degree[ne]--;
                    if(degree[ne]==1){
                        q.push(ne);
                    }
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};