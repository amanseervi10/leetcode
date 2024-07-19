class Solution {
public: 
    int dp[201][20001];
    bool solve(vector<int> arr,int sum,int n){
        for(int i=0; i<sum+1; i++) dp[0][i]=0;   
        for(int i=0; i<n+1; i++) dp[i][0]=1;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(j>=arr[i-1]){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];  
    }   

    bool canPartition(vector<int>& nums) {
        int k=0;
        for(int i=0; i<nums.size(); i++){
            k+=nums[i];
        }
        if(k%2!=0 || nums.size()==1) return false;
        return solve(nums,k/2,nums.size());
    }
};