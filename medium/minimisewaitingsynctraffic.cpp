class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime){
        int maxm =0;
        for(auto &x:lights){
            maxm = max(x, maxm);
        }
        int penalty = 0;
        for(auto &x: arrivalTime){
            int r = x%period;
            if(r>=maxm){
                penalty = max(penalty, period - r);
            }
        }
        return penalty;
    }
};