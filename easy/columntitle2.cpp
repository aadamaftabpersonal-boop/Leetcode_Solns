class Solution {
public:
    int titleToNumber(string columnTitle) {
        int title=0;
        int n = columnTitle.size()-1;
        for(int i=0;i<columnTitle.size();i++){
            title+=pow(26, n--) * (columnTitle[i]-'A'+1);
        }
        return title;
    }
};