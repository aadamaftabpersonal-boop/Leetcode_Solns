class Solution {
public:
    int missingInteger(vector<int>& nums){
        int currmax=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] - nums[i] == 1){
                currmax+=nums[i+1];
            }
            else{
                break;
            }
        }
        unordered_map<int, int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        while(mp[currmax]!=0){
            currmax++;
        }
        return currmax;
    }
};