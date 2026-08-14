class Solution {
public:
    int t[10001];
    int solve(int n){
        if(n==0){
            return 0;
        }
        if(t[n]!=-1){
            return t[n];
        }
        int minm = INT_MAX, steps=0;
        for(int i=1;i*i<=n;i++){
            steps = 1+ solve(n-(i*i));
            minm = min(minm, steps);
        }
        return t[n] = minm;
    }
    int numSquares(int n){
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};

class Solution {
private:
    bool isSquare(int n) {
        int r = sqrt(n);
        return r * r == n;
    }

public:
    int numSquares(int n) {
        // Case 1: n is a perfect square
        if (isSquare(n)) return 1;

        // Case 4: n is of the form 4^a * (8b + 7)
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;

        // Case 2: Check if n can be written as (a^2 + b^2)
        for (int i = 1; i * i <= n; i++) {
            if (isSquare(n - i * i)) return 2;
        }

        // Case 3: Otherwise, the answer must be 3
        return 3;
    }
};


class Solution {
public:
    int numSquares(int n) {
        // 1. Create DP array & set base case
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        // 2. Build subproblems from 1 to n
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                // 3. Exact same recurrence, replacing solve() with dp[]
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        
        return dp[n];
    }
};
tabulation approach
