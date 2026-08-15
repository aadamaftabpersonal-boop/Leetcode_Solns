class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        int total_xor = 0, non_zero=0;
        for(auto x: nums){
            total_xor^=x;
            if(x!=0)non_zero++;
        }
        if(non_zero==0)return 0;
        if(total_xor==0)return nums.size()-1;
        return nums.size();
    }
};