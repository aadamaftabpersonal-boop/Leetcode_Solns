class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target){
        int ans = 1000, min_dist=INT_MAX;
        for(int i=0;i<drones.size();i++){
            int x_dist= abs(drones[i][0] - target[0]);
            int y_dist = abs(drones[i][1] - target[1]);
            int dist = x_dist+y_dist;
            if(dist<=drones[i][2]){
                if(dist<min_dist){
                    ans = i;
                    min_dist = dist;
                }
            }
        }
        return ans==1000?-1: ans;
    }
};