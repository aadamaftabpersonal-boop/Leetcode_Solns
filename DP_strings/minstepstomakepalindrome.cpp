class Solution {
public:
    int t[501][501];
    int solve(int i, int j, string &s){
        if(i>=j)return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(s[i]==s[j]){
            return t[i][j] = solve(i+1, j-1, s);
        }
        else{
            return t[i][j] = 1+ min(solve(i+1, j, s), solve(i, j-1, s));
        }
    }
    int minInsertions(string s){
        memset(t, -1, sizeof(t));
        int n = s.size()-1;
        return solve(0, n, s);
    }
};