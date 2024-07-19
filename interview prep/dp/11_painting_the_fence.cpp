long long countWays(int n, int k){
    if(n==1) return k;
    else if(n==2) return k*k;

    
    long long mod=1e9 + 7;
    long long arr[n+1];
    arr[1]=k;
    arr[2]=k*k;

    for(int i=3; i<=n; i++){
        arr[i]=((k-1)*(arr[i-1]+arr[i-2]))%mod;
    }

    return arr[n];
}