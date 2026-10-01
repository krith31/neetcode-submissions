class DSU{
public:
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    bool isConnected(int a, int b){return findParent(a)==findParent(b);}
    void unionbysize(int a , int b){
        int pa=findParent(a);
        int pb=findParent(b);
        if(pa==pb){
            return;
        }
        if(size[pa]>=size[pb]){
            size[pa]+=size[pb];
            parent[pb]=pa;
        }
        else if(size[pa]<size[pb]){
            size[pb]+=size[pa];
            parent[pa]=pb;
        }
    }
};
class Solution {
public:
    int findMST(int n, vector<tuple<int,int,int,int>>& indexed_edges, int removed_edge_index=-1, int again_added_edge_index=-1){
        DSU dsu(n);
        int MST_wt=0;
        int edges_used=0;
        if(again_added_edge_index!=-1){
            for(auto [wt,a,b,idx]:indexed_edges){
                if (idx == again_added_edge_index) {
                    dsu.unionbysize(a, b);
                    MST_wt += wt;
                    edges_used++;
                    break;
                }
            }
        }
        for(auto edge:indexed_edges){
            auto[wt,a,b,idx]=edge;
            if(idx==removed_edge_index || idx==again_added_edge_index){
                continue;
            }
            if(!dsu.isConnected(a,b)){
                dsu.unionbysize(a,b);
                MST_wt+=wt;
                edges_used++;
            }
        }
        if(edges_used!=n-1){
            return INT_MAX;
        }
        return MST_wt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<tuple<int,int,int,int>> indexed_edges;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0], b=edges[i][1], wt=edges[i][2];
            indexed_edges.push_back({wt,a,b,i});
        }

        sort(begin(indexed_edges),end(indexed_edges));
        int MST_wt=findMST(n,indexed_edges);
        vector<vector<int>> ans_edges={{},{}};

        for(auto edge:indexed_edges){
            auto [wt,a,b,idx]=edge;
            int MST_without_cur_edge=findMST(n,indexed_edges,idx,-1);
            if(MST_without_cur_edge>MST_wt){
                ans_edges[0].push_back(idx);
            }
            else{
                int MST_with_cur_edge=findMST(n,indexed_edges,-1,idx);
                if(MST_with_cur_edge==MST_wt){
                    ans_edges[1].push_back(idx);
                }
            }
        }
        return ans_edges;

    }
};