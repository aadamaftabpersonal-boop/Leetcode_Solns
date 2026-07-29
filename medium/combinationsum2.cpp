class Solution {
public:
    void solve(int i, int remaining, vector<int> &candidates, vector<vector<int>> &result, vector<int> &temp){
        //1 1 2 5 6 7 10
        if(remaining==0){
            result.push_back(temp);
            return;
        }
        if(remaining<0 || i>=candidates.size()){
            return;
        }
        temp.push_back(candidates[i]);
        solve(i+1, remaining-candidates[i], candidates, result, temp);
        temp.pop_back();
        int next=i+1;
        while(next<candidates.size() && candidates[next]==candidates[next-1]){
            next++;
        }
        solve(next, remaining, candidates, result, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());   
        vector<int> temp;
        vector<vector<int>> result;
        solve(0, target, candidates, result, temp);
        return result;
    }
};