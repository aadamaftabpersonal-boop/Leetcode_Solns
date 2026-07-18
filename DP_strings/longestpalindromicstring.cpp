class Solution {
public:
    bool solve(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s){
        int maxlen=0;
        int start=-1, end=-1;
        int n = s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i, j, s)){
                    if(j-i+1>maxlen){
                        maxlen = j-i+1;
                        start = i;
                        end=j;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};