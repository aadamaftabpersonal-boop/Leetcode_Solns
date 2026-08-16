class Solution {
public:
    int maximumGap(string skill, string station){
        if(skill.size()<=1)return 0;
        int n = skill.size(), m=station.size();
        int j=0;
        vector<int> forward_pass(n, -1);
        for(int i=0;i<m;i++){
            if(j>=n)break;
            if(station[i]==skill[j]){
                forward_pass[j] = i;
                j++;
            }
        }
        vector<int> backward_pass(n, -1);
        j=n-1;
        for(int i=m-1;i>=0;i--){
            if(j<0)break;
            if(station[i]==skill[j]){
                backward_pass[j]=i;
                j--;
            }
        }
        int maxm= 0;
        for(int i=n-1;i>=1;i--){
            maxm = max(maxm, backward_pass[i] - forward_pass[i-1]);
        }
        return maxm;
    }
};