int dp[501][2001];
int solve(vector<int> &nums, int index, int curr,int k){

    if(index==nums.size()) return 0;
    
    if(dp[index][curr]!=-1) return dp[index][curr];

    int pick=INT_MAX,notpick;
    if(curr!=0){
        if(curr+nums[index]+1<=k){
            pick=solve(nums,index+1,curr+nums[index]+1,k);
        }
    }
    else{
        pick=solve(nums,index+1,curr+nums[index],k);
    }
    notpick=(k-curr)*(k-curr)+solve(nums,index+1,nums[index],k);
    return dp[index][curr]=min(pick,notpick);
}

int solveWordWrap(vector<int> nums, int k)
{
    memset(dp,-1,sizeof(dp));
    return solve(nums,0,0,k);
}