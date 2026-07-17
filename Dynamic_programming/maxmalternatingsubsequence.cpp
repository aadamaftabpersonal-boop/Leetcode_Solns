class Solution {
public:
    long long dp[100001][2];
    long long solve(int i, int n, int flipped, vector<int> &nums){
        if(i>=n)return 0;
        if(dp[i][flipped]!=-1)return dp[i][flipped];
        long long take=0, no_take=0;
        if(flipped){
            take = nums[i] + solve(i+1, n, flipped^1, nums);
        }
        else{
            take= (-1)*(nums[i]) + solve(i+1, n, flipped^1, nums);
        }
        no_take = solve(i+1, n, flipped, nums);
        return dp[i][flipped] = max(take, no_take);
    }
    long long maxAlternatingSum(vector<int>& nums){
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, 1, nums);
    }
};