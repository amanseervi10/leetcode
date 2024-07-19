//---------------Recursion----------------------

// #include<bits/stdc++.h>
// using namespace std;

// int solve(int length[],int price[],int n, int i){
//     if(i<0 || n<0) return 0;
//     if(n>=length[i]) return max(price[i]+solve(length,price,n-length[i],i),
//                                              solve(length,price,n,i-1));
//     else return solve(length,price,n,i-1);
// }

// int main(){
//     int n; cin>>n;
//     int length[n],price[n];
//     for(int i=0;i<n; i++) cin>>length[i];
//     for(int i=0;i<n; i++) cin>>price[i];
//     cout<<solve(length,price,n,n-1);
//     return 0;
// }


//-----------------Tabulation--------------------

#include<bits/stdc++.h>
using namespace std;

int dp[100][10001];
int solve(int n, int k ,int length[],int price[]){
    for(int i=0; i<=n; i++) dp[0][i]=0;
    for(int i=0; i<=k; i++) dp[i][0]=0;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(j>=length[i-1]){
                dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-length[i-1]]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[k][n];
}

int main(){
    int n; cin>>n;
    int k; cin>>k;
    int length[k],price[k];
    for(int i=0;i<k; i++) cin>>length[i];
    for(int i=0;i<k; i++) cin>>price[i];
    cout<<solve(n,k,length,price);
    return 0;
}