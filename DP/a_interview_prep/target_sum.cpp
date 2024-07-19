//same as subset with given difference problem 
//see aditya verma video

//recursive function
// int solve(vector<int> &A, int k,int i){

//     if(k==0) return 1;
//     if(i<0) return 0;
    
//     return solve(A,k-A[i],i-1)+solve(A,k,i-1);
// }

void solve(vector<int> &A, int k){
    int dp[A.size()+1][k+1];
    for(int i=0; i<k+1; i++) dp[0][i]=0;
    for(int i=0; i<A.size()+1; i++) dp[i][0]=1;

    for(int i=0; i<A.size()+1; i++){
        for(int j=0; j<k+1; j++){
            if(j>=A[i-1]) dp[i][j]=dp[i-1][j]+dp[i-1][j-A[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[A.size()][k];
}

int findTargetSumWays(vector<int> &A, int target)
{
    int sum=0;
    target=abs(target);
    for(int i=0; i<A.size();i++) sum+=A[i];
    int k=(sum-target)/2;
    if(k<0 || (sum-target)%2) return 0;

    return solve(A,k);
}