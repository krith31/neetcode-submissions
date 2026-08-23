class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> vec;
        for(int i=0;i<position.size();i++){
            double time=(double)(target-position[i])/speed[i];
            vec.push_back({position[i],time});
        }
        sort(vec.rbegin(),vec.rend());
        int fleets=0;
        double ltime=0;
        for(auto it:vec){
            double time=it.second;
            if(time>ltime){
                fleets++;
                ltime=time;
            }
        }
        return fleets;
    }
};
