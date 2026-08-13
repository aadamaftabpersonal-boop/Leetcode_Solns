class Solution {
public:
    int t[301][11];
    int solve(vector<int> &jd, int n, int d, int i){
        if(t[i][d]!=-1){
            return t[i][d];
        }
        if(d==1){
            int maxm = jd[i];
            for(int j=i;j<n;j++){
                maxm = max(maxm, jd[j]);
            }
            return t[i][1] = maxm;
        }
        int maxm = jd[i];
        int finalresult = INT_MAX;
        for(int k=i;k<=n-d;k++){
            maxm = max(maxm, jd[k]);
            int result = maxm + solve(jd, n, d-1, k+1);
            finalresult = min(finalresult, result);
        }
        return t[i][d] = finalresult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d){
        memset(t, -1, sizeof(t));
        int n = jobDifficulty.size();
        if(n<d)return -1;
        return solve(jobDifficulty, n, d, 0);
    }
};