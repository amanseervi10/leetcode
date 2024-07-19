int countFriendsPairings(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;

    int mod=1e9+7;

    long long prev1=1, prev2=2;

    for(int i=3; i<=n; i++){
        int curr=(prev2 + ((i-1)*prev1)%mod)%mod;
        prev1=prev2;
        prev2=curr;
    }
    return prev2;
}