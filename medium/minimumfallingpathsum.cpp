class Solution {
public:
    int t[101][101];
    int solve(int i, int j, int n, vector<vector<int>>&matrix){
        if(i>n-1 || j>n-1 || j<0 || i<0){
            return 1e9;
        }
        if(i==n-1)return t[i][j] = matrix[i][j];
        if(t[i][j]!=-1e9)return t[i][j];
        int down=0, leftdiag=0, rightdiag=0;
        down = solve(i+1, j, n, matrix);
        leftdiag = solve(i+1, j-1, n, matrix);
        rightdiag =solve(i+1, j+1, n, matrix);
        return t[i][j] = matrix[i][j] + min({down, leftdiag, rightdiag});
    }
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size(), minm=1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                t[i][j]=-1e9;
            }
        }
        for(int j=0;j<n;j++){
            minm = min(minm, solve(0, j, n, matrix));
        }
        return minm;
    }
};