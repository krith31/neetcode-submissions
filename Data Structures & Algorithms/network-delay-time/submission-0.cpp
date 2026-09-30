class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using T=pair<int,int>;
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        dist[k]=0;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int dis=it.first;
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[v]>dis+wt){
                    dist[v]=dis+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
