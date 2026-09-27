class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegree(n+1,0);
        vector<int> indegree(n+1,0);
        for(int i=0;i<trust.size();i++){
            int a=trust[i][0];
            int b=trust[i][1];
            outdegree[b]++;
            indegree[a]++;
        }
        for(int i=1;i<=n;i++){
            if(outdegree[i]==n-1 && indegree[i]==0){
                return i;
            }
        }
        return -1;
    }
};