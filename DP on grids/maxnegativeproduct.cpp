class Solution {
public:
    int m, n;
    typedef long long ll;
    pair<ll, ll> t[16][16];
    bool visited[16][16];
    pair<ll, ll> solve(int i, int j, vector<vector<int>> &grid){
        if(i==m-1 && j==n-1){
            return {grid[i][j], grid[i][j]};
        }
        if(visited[i][j]){
            return t[i][j];
        }
        ll maxval = LLONG_MIN;
        ll minval = LLONG_MAX;
        visited[i][j]=true;
        if(i+1<m){
            auto [downmax, downmin] = solve(i+1, j, grid);
            maxval = max({maxval, grid[i][j] * downmax, grid[i][j] * downmin});
            minval = min({minval, grid[i][j]*downmax, grid[i][j] * downmin});
        }
        if(j+1<n){
            auto [rightmax, rightmin] = solve(i, j+1, grid);
            maxval = max({maxval, grid[i][j] * rightmax, grid[i][j] * rightmin});
            minval = min({minval, grid[i][j] * rightmax, grid[i][j] * rightmin});
        }
        return t[i][j] = {maxval, minval};
    }
    int maxProductPath(vector<vector<int>>& grid){
        m= grid.size();
        n = grid[0].size();
        memset(visited, false, sizeof(visited));
        auto [maxprod, minprod] = solve(0, 0, grid);
        return maxprod<0 ?-1: maxprod % 1000000007;
    }
};