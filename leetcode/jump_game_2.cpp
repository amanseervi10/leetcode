class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans[n];
        memset(ans,INT_MAX,sizeof(ans));
        ans[0]=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]==0) continue;
            for(int j=1; j<=nums[i] && j+nums[i]<n; j++){
                ans[i+j]=min(ans[i+j],ans[i]+1);
            }
        }
        return ans[n-1];
    }
};