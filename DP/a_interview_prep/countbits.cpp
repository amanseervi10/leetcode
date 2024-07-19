class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0) return ans;
        ans.push_back(1);
        if(n==1) return ans;

        int curr=1; 
        for(int i=2; i<n+1; i+=2){
            ans.push_back(ans[curr]);
            if(ans.size()!=n+1) ans.push_back(ans[curr]+1);
            curr++;
        }

        return ans;
    }
};