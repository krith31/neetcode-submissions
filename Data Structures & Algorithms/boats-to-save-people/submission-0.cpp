class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        int ans=0;
        int count=0;
        while(i<j){
            if(people[i]+people[j]<=limit){
                ans=ans+1;
                count=count+2;
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit){
                j--;
            }
        }
        if(count!=n){
            ans=ans+(n-count);
        }
        return ans;
    }
};