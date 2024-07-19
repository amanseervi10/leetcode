class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0];
        int max_profit=0;
        for(int i=1; i<prices.size(); i++){
            max_profit=max(max_profit,prices[i]-mn);
            mn=min(mn,prices[i]);
        }
        return max_profit;
    }
};