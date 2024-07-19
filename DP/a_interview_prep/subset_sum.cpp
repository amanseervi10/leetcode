//recursion
// bool solve(vector<int> arr, int sum,int i){
//     if(sum==0) return true;
//     else if(sum<0 || i<0) return false;

//     return (solve(arr,sum-arr[i],i-1) || solve(arr,sum,i-1));
// }

//memoization
// int dp[101][101];
// bool solve(vector<int> arr, int sum, int i){
//     if(sum==0) return true;
//     else if(sum<0 || i<0) return false;

//     if(dp[i][sum]!=-1) return dp[i][sum];

//     return dp[i][sum]=(solve(arr,sum-arr[i],i-1) || solve(arr,sum,i-1));
// }

//but this ain't no good as the contrainst for sum is 10^5 which is too much
//we need space optimized approach

//We can do tabulation but then even there we need same amount of space
//but then in tabulation do we need all the rows at once?
//we only need the curr and the prev row at any given moment
//we can use this to our advantage

bool isSubsetSum(vector<int> arr, int sum)
{
    vector<int> prev(sum+1,0),curr(sum+1,0);
    prev[0]=1;  //as both of these are always one in the table, as if sum is 0, we always have the null set
    curr[0]=1;

    for(int i=1; i<=arr.size(); i++){
        for(int j=1; j<=sum; j++){
            if(j>=arr[i-1]){
                curr[j]=prev[j] || prev[j-arr[i-1]];
            }
            else curr[j]=prev[j];
        }
        prev=curr;
    }

    return curr[sum];

}