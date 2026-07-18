class Solution {
public:
    int dp[2501][2501];
    int solve(int i, int prev, int n, vector<int> &nums){
        if(i>=n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0, no_take=0;
        if(prev==-1 || nums[i]>nums[prev]){
            take = 1+solve(i+1, i, n, nums);
        }
        no_take = solve(i+1, prev, n, nums);
        return dp[i][prev+1] = max(take, no_take);
    }
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, n, nums);
    }
};