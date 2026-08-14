class Solution {
public:
    int solve(int i, int n, int prev, vector<vector<int>> &times, vector<vector<int>> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0, no_take=0;
        if(prev==-1 || times[i][0]>=times[prev][1]){
            take = times[i][2]+ solve(i+1, n, i, times, dp);
        }
        no_take = solve(i+1, n, prev, times, dp);
        return dp[i][prev+1] = max(take, no_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n = startTime.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector<vector<int>> times(n, vector<int>(3, 0));
        for(int i=0;i<n;i++){
            times[i][0] = startTime[i];
            times[i][1] = endTime[i];
            times[i][2] = profit[i];
        }
        sort(times.begin(), times.end());
        return solve(0, n, -1, times, dp);
    }
};


//NlogN - using binary search
class Solution {
public:
    int findnext(int i, vector<vector<int>> &times, int n){
        int nextidx= -1;
        int target = times[i][1];
        int start=i+1, end = n-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(times[mid][0]>=target){
                nextidx = mid;
                end= mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return nextidx;
    }
    int solve(int i, int n, vector<vector<int>> &times, vector<int> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int take=0, no_take=0;
        no_take = solve(i+1, n, times, dp);
        take = times[i][2];
        int nextidx = findnext(i, times, n);
        if(nextidx!=-1){
            take+= solve(nextidx, n, times, dp);
        }
        return dp[i] = max(take, no_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        int n = startTime.size();
        vector<int> dp(n, -1);
        vector<vector<int>> times(n, vector<int>(3, 0));
        for(int i=0;i<n;i++){
            times[i][0] = startTime[i];
            times[i][1] = endTime[i];
            times[i][2] = profit[i];
        }
        sort(times.begin(), times.end());
        return solve(0, n, times, dp);
    }
};