class Solution {
public:
    int t[5001][2];
    int solve(int i, int n, vector<int> &prices, bool buy){
        if(i>=n)return 0;
        int profit=0;
        if(t[i][buy]!=-1) return t[i][buy];
        if(buy){
            int take = solve(i+1, n, prices,false) - prices[i];
            int not_take = solve(i+1, n, prices, true); 
            profit = max({profit, take, not_take});
        }
        else{
            int sell = prices[i] + solve(i+2, n, prices, true);
            int not_sell = solve(i+1, n, prices, false);
            profit = max({profit, sell, not_sell});
        }
        return t[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices){
        memset(t, -1, sizeof(t));
        int n = prices.size();
        return solve(0, n, prices, true);
    }
};