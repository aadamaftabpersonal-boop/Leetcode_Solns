class Solution {
public:
    int solve(int i, int n, int xor_till_now, vector<int>&nums, vector<vector<int>> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][xor_till_now]!=-1)return dp[i][xor_till_now];
        int take=0, no_take=0;
        if(nums[i] == 0 || (xor_till_now ^ nums[i])!=0){
            take=1+solve(i+1, n, xor_till_now^nums[i], nums, dp);
        }
        else{
            xor_till_now = 0;
        }
        no_take = solve(i+1, n, xor_till_now, nums, dp);
        return dp[i][xor_till_now] = max(take, no_take);
    }
    int longestSubsequence(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n, 0, nums, dp);
    }
};

//useful for N<=1000 or 2000 not more as XOR grows with power of 2

//failed approach2
class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        //forward pass
        int xor_till_now=0, curr_max=0, n=nums.size(), forward_max=0;
        for(int i=0;i<n;i++){
            xor_till_now ^= nums[i];
            if(xor_till_now!=0)curr_max++;
            else curr_max=0;
            forward_max = max(forward_max, curr_max);
        }
        //backward pass
        xor_till_now=0;
        curr_max=0;
        n=nums.size(); 
        int backward_max=0;
        for(int i=n-1;i>=0;i--){
            xor_till_now ^= nums[i];
            if(xor_till_now!=0)curr_max++;
            else curr_max=0;
            backward_max = max(backward_max, curr_max);
        }
        return max(forward_max, backward_max);
    }
};
//this is right code for longest subarrray not subsequence

class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        int total_xor = 0, non_zero=0;
        for(auto x: nums){
            total_xor^=x;
            if(x>0)non_zero++;
        }
        if(non_zero==0)return 0;
        if(total_xor==0)return nums.size()-1;
        return nums.size();
    }
};
//correct code
/*
logic- you need only one element to make xor zero*/