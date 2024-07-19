int solve(int w,int wt[],int val[],int n,int ans){

    if(n<0) return ans;
    
    if(w<wt[n]) return solve(w,wt,val,n-1,ans);
    else return max(solve(w-wt[n],wt,val,n-1,ans+val[n]),solve(w,wt,val,n-1,ans));
}

int knapSack(int W, int wt[], int val[], int n){
    return solve(W,wt,val,n-1,0);
}   