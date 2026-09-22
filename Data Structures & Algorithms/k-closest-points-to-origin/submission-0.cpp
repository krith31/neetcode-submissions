class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist=x*x+y*y;
            minHeap.push({dist,i});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            int index=minHeap.top().second;
            minHeap.pop();
            ans.push_back(points[index]);
        }
        return ans;
    }
};
