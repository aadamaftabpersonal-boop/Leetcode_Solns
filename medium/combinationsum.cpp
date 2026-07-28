class Solution {
public:
    void solve(int i, int remaining, vector<int> &temp, vector<vector<int>> &result, vector<int> &arr){
        if(i>=arr.size())return;
        if(remaining==0){
            result.push_back(temp);
            return;
        }
        if(remaining<0 || i>=arr.size()){
            return;
        }
        //take
        temp.push_back(arr[i]);
        solve(i, remaining-arr[i], temp, result, arr);
        temp.pop_back();
        solve(i+1, remaining, temp, result, arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> result;
        vector<int> temp;
        solve(0, target, temp, result, candidates);
        return result;
    }
};

//usually not a safe practice to put i>=arr.size() at the top