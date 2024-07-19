//memization solution
// class Solution {
// public:

//     int solve(string a, string b, int i, int j,vector<vector<int>> &dp){

//         if(i<0 && j<0) return 0;
//         else if(i<0){
//             int sum=0;
//             for(int k=0; k<=j; k++) sum+=b[k];
//             return sum;
//         }
//         else if(j<0){
//             int sum=0;
//             for(int k=0; k<=i; k++) sum+=a[k];
//             return sum;
//         }

//         if(dp[i][j]!=-1) return dp[i][j];
//         if(a[i]==b[j]) return dp[i][j]=solve(a,b,i-1,j-1,dp);

//         else{
//             int temp1=a[i]+solve(a,b,i-1,j,dp);
//             int temp2=b[j]+solve(a,b,i,j-1,dp);
//             return dp[i][j]=min(temp1,temp2);
//         }
//     }

//     int minimumDeleteSum(string a, string b) {
//         vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
//         return solve(a,b,a.length()-1,b.length()-1,dp);
//     }
// };



//space-optimized tabulation
class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int n=a.length(),m=b.length();

        vector<int> prev(m+1,0),curr(m+1,0);

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 && j==0) curr[j]=0;
                else if(i==0) curr[j]=curr[j-1]+b[j-1];
                else if(j==0) curr[j]=prev[j]+a[i-1];
                else{
                    if(a[i-1]==b[j-1]) curr[j]=prev[j-1];
                    else curr[j]=min(b[j-1]+curr[j-1],a[i-1]+prev[j]);
                }
            }
            prev=curr;
        }

        return prev[m];
    }
};