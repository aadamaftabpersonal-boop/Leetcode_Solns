class Solution {
public:
    void solve(int i, string &s, vector<vector<string>> &result, vector<string> &currpartition, vector<vector<bool>> &t) {
        if (i == s.length()) {
            result.push_back(currpartition);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (t[i][j]) {
                currpartition.push_back(s.substr(i, j - i + 1));
                solve(j + 1, s, result, currpartition, t);
                currpartition.pop_back();   
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (L == 2) {
                    t[i][j] = (s[i] == s[j]);
                } else {
                    t[i][j] = (s[i] == s[j]) && t[i + 1][j - 1];
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currpartition;
        solve(0, s, result, currpartition, t);

        return result;
    }
};