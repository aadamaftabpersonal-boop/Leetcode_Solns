class Solution {
public:
    int dp[101];
    int solve(int i, int n, vector<int> &nums){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take = solve(i+2, n, nums) + nums[i];
        int no_take = solve(i+1, n, nums);
        return dp[i] = max(take, no_take);
    }
    int rob(vector<int>& nums){
        memset(dp, -1, sizeof(dp));
        int  n =nums.size();
        if(n==1) return nums[0];
        int path1 = solve(0, n-1, nums);
        memset(dp, -1, sizeof(dp));
        int path2 = solve(1, n, nums);
        return max(path1, path2);
    }
};