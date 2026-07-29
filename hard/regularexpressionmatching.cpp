class Solution {
public:
    int t[21];
    bool solve(string s, string p){
        if(p.length()==0){
            if(s.length()==0)return true;
            return t[i] = false;
        }
        if(t[i]!=false)return t[i];
        bool first_char_match = false;
        if(s.length()>0 && (s[0]==p[0] || p[0]=='.')){
            first_char_match = true;
        }
        if(p[1]=='*'){
            bool no_take = solve(s, p.substr(2));
            bool take = first_char_match && solve(s.substr(1), p);
            return t[i] = take || no_take;
        }
        return t[i] = first_char_match && solve(s.substr(1), p.substr(1));
    }
    bool isMatch(string s, string p){
        return solve(s, p);
    }
};


class Solution {
public:
    int t[21][21];
    bool solve(int i, int j, string &s, string &p){
        if(j==p.length()){
            if(i==s.length())return t[i][j] = true;
            return t[i][j]=false;
        }
        if(t[i][j]!=-1)return t[i][j];
        bool first_char_match = false;
        if(i<s.length() && (s[i]==p[j] || p[j]=='.')){
            first_char_match = true;
        }
        if(j+1 < p.length() && p[j+1]=='*'){
            bool no_take = solve(i, j+2, s, p);
            bool take = first_char_match && solve(i+1, j, s, p);
            return t[i][j] = take || no_take;
        }
        return t[i][j] = first_char_match && solve(i+1, j+1, s, p);
    }
    bool isMatch(string s, string p){
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, p);
    }
};