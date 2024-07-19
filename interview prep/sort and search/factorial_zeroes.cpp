// A very good question of binary search

int count(int n){
    int d=5;
    int ans=0;
    while(d<=n){
        ans+=(n)/d;
        d*=5;
    }
    return ans;
}

int findNum(int n)
{
    int low=0,high=5*n;
    int ans;

    while(high>=low){
        int m=low+ (high-low)/2;
        int k=count(m);
        if(m>=n){
            ans=m;
            high=m-1;
        }
        else{
            low=m+1;
        }
    }
    return ans;
}