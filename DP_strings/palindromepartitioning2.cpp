class Solution {
public:
    int t[2000];
    int isPalinMemo[2000][2000];

    bool ispalin(string &s, int i, int j) {
        if (i >= j) return true;
        if (isPalinMemo[i][j] != -1) return isPalinMemo[i][j];
        
        if (s[i] == s[j]) {
            return isPalinMemo[i][j] = ispalin(s, i + 1, j - 1);
        }
        return isPalinMemo[i][j] = false;
    }

    // solve(i) returns the minimum cuts needed for suffix s[i...n-1]
    int solve(int i, string &s) {
        int n = s.size();
        if (i >= n || ispalin(s, i, n - 1)) return 0;

        if (t[i] != -1) return t[i];

        int result = INT_MAX;
        // Try every possible end point for the first palindrome segment s[i...k]
        for (int k = i; k < n; k++) {
            if (ispalin(s, i, k)) {
                int temp = 1 + solve(k + 1, s);
                result = min(result, temp);
            }
        }

        return t[i] = result;
    }

    int minCut(string s) {
        memset(t, -1, sizeof(t));
        memset(isPalinMemo, -1, sizeof(isPalinMemo));
        return solve(0, s);
    }
};