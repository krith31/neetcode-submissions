class Solution {
private:
    double dfs(const string& u, const string& v, unordered_set<string>& vis, map<string,vector<pair<string,double>>>& mp){
        if(u==v) return 1.0;
        vis.insert(u);
        for(const auto& it:mp[u]){
            string n=it.first;
            double w=it.second;

            if(vis.find(n)==vis.end()){
                double result=dfs(n,v,vis,mp);
                if(result!=-1.0){
                    return result*w;
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<equations.size();i++){
            string s1=equations[i][0];
            string s2=equations[i][1];
            mp[s1].push_back({s2,values[i]});
            mp[s2].push_back({s1,1.0/values[i]});
        }

        vector<double> results;
        for(const auto& q:queries){
            string u=q[0];
            string v=q[1];

            if(mp.find(u)==mp.end() || mp.find(v)==mp.end()){
                results.push_back(-1.0);
            }
            else{
                unordered_set<string> vis;
                results.push_back(dfs(u,v,vis,mp));
            }
        }
        return results;
    }
};