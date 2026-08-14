class Solution {
public:
    bool condition(string &s){
        unordered_map<char, int> mp;
        for(auto ch: s){
            mp[ch]++;
        }
        for(auto x:mp){
            if(x.second>2)return false;
        }
        return true;
    }
    int maximumLengthSubstring(string s){
        int maxlen =0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                string t = s.substr(j, i-j+1);
                if(condition(t)){
                    maxlen = max(maxlen, i-j+1);
                }
            }
        }
        return maxlen;
    }
};

//leetcode 3090


//optimal soln
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        vector<int> count(26, 0); // Frequency map for lowercase letters
        
        int j = 0; // Left pointer
        
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++; // Include current character
            
            // Shrink window from the left if frequency > 2
            while (count[s[i] - 'a'] > 2) {
                count[s[j] - 'a']--;
                j++;
            }
            
            // Update maximum length found so far
            maxlen = max(maxlen, i - j + 1);
        }
        
        return maxlen;
    }
};

//slidingwindow is weak