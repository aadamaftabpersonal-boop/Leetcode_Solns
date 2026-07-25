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
