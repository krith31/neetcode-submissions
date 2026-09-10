class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        std::map<int, int> count;
        for (int num : hand) {
            count[num]++;
        }

        for (auto const& [card, freq] : count) {
            while (count[card] > 0) {
                
                for (int i = 0; i < groupSize; ++i) {
                    if (count[card + i] == 0) {
                        return false; 
                    }
                    count[card + i]--;
                }
            }
        }
        
        return true;
    }
};
