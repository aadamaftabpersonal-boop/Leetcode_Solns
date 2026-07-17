class Solution {
public:
    int dp[1001][1001];
    int solve(int i, int prev, int n, vector<vector<int>> &nums){
        if(i>=n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0, no_take=0;
        if(prev==-1 || nums[i][0]>nums[prev][1]){
            take = 1 + solve(i+1, i, n, nums);
        }
        no_take = solve(i+1, prev, n, nums);
        return dp[i][prev+1] = max(take, no_take);
    }
    int findLongestChain(vector<vector<int>>& pairs){
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, n, pairs);
    }
};