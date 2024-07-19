class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int front[n],back[n];
        
        int mn=prices[0],max_profit=0;
        for(int i=0; i<n; i++){
            max_profit=max(max_profit,prices[i]-mn);
            mn=min(mn,prices[i]);
            front[i]=max_profit;
        }

        int mx=prices[n-1];
        max_profit=0;
        for(int i=n-1; i>=0; i--){
            max_profit=max(max_profit,mx-prices[i]);
            mx=max(mx,prices[i]);
            back[i]=max_profit;
        }

        int ans=0;
        ans=max(front[n-1],back[0]);
        for(int i=1; i<n-1; i++){
            ans=max(ans,front[i]+back[i+1]);
        }

        return ans;
    }
};