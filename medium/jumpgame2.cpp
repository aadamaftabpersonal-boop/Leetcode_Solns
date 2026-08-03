class Solution {
public:
    int solve(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i>n-1){
            return 1e9;
        }
        if(dp[i]!=1e9)return dp[i];
        if(i==n-1){
            return 0;
        }
        for(int j=1;j<=nums[i];j++){
            if(nums[i]==0 && i+j<n-1){
                continue;
            }
            dp[i] = min(dp[i], 1 + solve(i+j, n, nums, dp));
        }
        return dp[i];
    }
    int jump(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+1, 1e9);
        return solve(0, n, nums, dp);
    }
};


/*
mistake 1:
1. not using the memoization check
2. not checking out of bounds
3. u dont need to immediately return, you can just update dp[i] and then return
*/