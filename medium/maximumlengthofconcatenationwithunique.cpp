class Solution {
public:
    bool distinct(string s1, string s2){
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s2.size();j++){
                if(s1[i]==s2[j]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isdistinct(string s1){
        sort(s1.begin(), s1.end());
        for(int i=0;i<s1.size()-1;i++){
            if(s1[i]==s1[i+1])return false;
        }
        return true;
    }
    int t[17];
    int solve(int i, int n, vector<string> &arr, string s){
        if(i>=n){
            return 0;
        }
        int take=0, not_take = 0;
        if(isdistinct(arr[i]) && distinct(s, arr[i])){
            take = arr[i].size() + solve(i+1, n, arr, s+arr[i]);
        }
        not_take = solve(i+1, n, arr, s);
        return t[i] = max(take, not_take);
    }
    int maxLength(vector<string>& arr){
        int n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(0, n, arr, "");
    }
};