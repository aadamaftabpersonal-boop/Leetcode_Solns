class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int maxm = 0;
        unordered_map<char, int> mp;
        int i=0, j=0;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                while(mp.find(s[j])!=mp.end()){
                    mp.erase(s[i]);
                    i++;
                }
            }
            maxm = max(maxm, j-i+1);
            mp[s[j]]++;
            j++;
        }
        return maxm;
    }
};

/*
optimal approach
reduce overhead of deletion, maintain last seen index
vector instead of map for constant space
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxm = 0;
        vector<int> lastIndex(256, -1); // Tracks last index of each ASCII char
        
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (lastIndex[s[j]] != -1) {
                i = max(i, lastIndex[s[j]] + 1); // Direct jump
            }
            maxm = max(maxm, j - i + 1);
            lastIndex[s[j]] = j; // Update position
        }
        
        return maxm;
    }
};

//DP approach
class Solution {
public:
    string longestPalindrome(string s){
        bool t[1001][1001];
        memset(t, false, sizeof(t));
        int n = s.size();
        if(n<=1)return s;
        for(int i=0;i<n;i++){
            t[i][i]=true;
        }
        int start=0, maxlen=1;
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j = i+l-1;
                if(s[i]==s[j]){
                    if(l==2 || t[i+1][j-1]){
                        t[i][j]=true;
                        if(l>maxlen){
                            start=i;
                            maxlen=l;
                        }
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};

//expandaroundcenter
class Solution {
public:
    int maxlen=0;
    int start=0;
    void expandaroundcenter(int i, int j, string &s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;j++;
        }
        int len = j-i-1;
        if(len>maxlen){
            maxlen = len;
            start = i+1;
        }
    }
    string longestPalindrome(string s){
        for(int i=0;i<s.size();i++){
            expandaroundcenter(i, i, s);
            expandaroundcenter(i, i+1, s);
        }
        return s.substr(start, maxlen);
    }
};