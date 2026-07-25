class Solution {
public:
    bool ispalindrome(string &s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s){
        string ans = "";
        int maxm = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s, i, j)){
                    if(j-i+1 > maxm){
                        ans = s.substr(i, j-i+1);
                        maxm = j-i+1;
                    }
                }
            }
        }
        return ans;
    }
};