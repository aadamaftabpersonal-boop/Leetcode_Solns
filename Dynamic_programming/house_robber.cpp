class Solution {
public:
    int dp[101];
    int solve(int i, int n, vector<int> &nums){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take = nums[i] + solve(i+2, n, nums);
        int no_take= solve(i+1, n, nums);
        return dp[i] = max(take, no_take);
    }
    int rob(vector<int> &nums){
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0, n, nums);
    }
};