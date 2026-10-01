class DSU{
    vector<int> parent, size;
    int components;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        components=n;
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            if(size[rootX]<size[rootY]) swap(rootX,rootY);
            parent[rootY]=rootX;
            size[rootX]+=size[rootY];
            components--;
        }
    }
    bool isConnected(){
        return components==1;
    }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int max_val=*max_element(nums.begin(),nums.end());
        if(max_val==1) return false;
        vector<int> spf(max_val+1);
        for(int i=1;i<=max_val;i++) spf[i]=i;
        for(int i=2;i*i<=max_val;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=max_val;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }
        DSU dsu(n);

        vector<int> prime_to_index(max_val+1,-1);
        for(int i=0;i<n;i++){
            int x=nums[i];
            while(x>1){
                int p=spf[x];
                if(prime_to_index[p]!=-1){
                    dsu.unite(i,prime_to_index[p]);
                }
                else{
                    prime_to_index[p]=i;
                }
                while(x%p==0){
                    x=x/p;
                }
            }
        }
        return dsu.isConnected();
    }
};