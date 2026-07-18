class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr){
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mp;
        int i = 1;
        for(auto x: sorted){
            if(mp.find(x)==mp.end()){
                mp[x]=i++;
            }
        }   
        vector<int> result;
        for(auto x:arr){
            result.push_back(mp[x]);
        }
        return result;
    }
};