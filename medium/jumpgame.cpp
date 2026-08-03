class Solution {
public:
    bool solve(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i>n-1){
            return false;
        }
        if(i==n-1){
            return dp[i] = true;
        }
        if(nums[i]==0){
            return dp[i]=false;
        }
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(solve(i+j, n, nums, dp)){
                return dp[i]=true;
            }
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, nums, dp);
    }
};

/*
mistakes: 
1. return dp[i] = smth when i>n-1 is wrong
2. use dp(n, -1) instead of bool
3. -1 is a truthy value
4. check if some branch returns then set dp[i] = true*/