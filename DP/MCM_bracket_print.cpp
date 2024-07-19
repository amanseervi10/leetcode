//Avilable on gfg practice

//memoization
int dp[30][30];
int cut[30][30];

int solve(int arr[],int i,int j){
    
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans=INT_MAX;
    int index=0;    
    for(int k=i; k<j; k++){
        int a=solve(arr,i,k);
        int b=solve(arr,k+1,j);
        int c=arr[i-1]*arr[k]*arr[j];
        if(a+b+c<ans){
            ans=a+b+c;
            index=k;
        }
    }
    cut[i][j]=index;
    return dp[i][j]=ans;
}

string make_string(int i, int j){
    if(i==j){
        string k="";
        k+='A'+i-1;
        return k;
    }

    else{
        int k=cut[i][j];
        string temp=make_string(i,k)+make_string(k+1,j);
        temp='('+temp+')';
        return temp;
    }
}

string matrixChainOrder(int p[], int n)
{
    memset(dp,-1,sizeof(dp));
    string ans="";
    for(int i=0; i<n-1; i++){
        ans+=('A'+i);
    }
    solve(p,1,n-1);
    return make_string(1,n-1);
}