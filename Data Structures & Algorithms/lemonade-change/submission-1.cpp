class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int den_5=0;
        int den_10=0;
        for(auto b:bills){
            if(b==5){
                den_5++;
            }
            else if(b==10){
                den_10++;
                if(den_5>0){
                    den_5--;
                }
                else{
                    return false;
                }
            }
            else{
                if(den_5>0 && den_10>0){
                    den_5--;
                    den_10--;
                }
                else if(den_5>=3){
                    den_5=den_5-3;
                }
                else{
                    return false;
                }
            }

        }
        return true;
    }
};