class Solution {
public:
    int t[201][201];
    int m;
    int n;
    int solve(int i, int j, vector<vector<int>> &dungeon){
        if(i>=m || j>=n){
            return 1e9;
        }
        if(t[i][j]!=-1)return t[i][j];
        if(i==m-1 && j==n-1){
            if(dungeon[i][j]>0)return 1;
            return abs(dungeon[i][j])+1;
        }
        int right = solve(i, j+1, dungeon);
        int down = solve(i+1, j, dungeon);
        int result = min(down, right) - dungeon[i][j];
        return t[i][j] = (result>0)?result: 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(t, -1, sizeof(t));
        m = dungeon.size();
        n = dungeon[0].size();
        return solve(0, 0, dungeon);
    }
};