class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0];
        int profit=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]-mn>0){
                profit+=prices[i]-mn;
                mn=prices[i];
            }
            mn=min(mn,prices[i]);
        }
        return profit;
    }
};