// #include<bits/stdc++.h>
// using namespace std;

// int dp[100][100];
// int solve(string x,string y){
//     for(int i=0; i<=x.length(); i++) dp[0][i]=0;
//     for(int i=0; i<=y.length(); i++) dp[i][0]=0;
//     for(int i=1; i<=y.length(); i++){
//         for(int j=1; j<=x.length(); j++){
//             if(x[j-1]==y[i-1]) dp[i][j]=1+dp[i-1][j-1];
//             else{
//                 dp[i][j]=0;
//             }
//         }
//     }
//     return dp[y.length()][x.length()];
// }

// int main(){
//     string x,y; cin>>x>>y;
//     cout<<solve(x,y);
//     return 0;
// }



class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int> nums1,vector<int> nums2){
        for(int i=0; i<=nums1.size(); i++) dp[0][i]=0;
        for(int i=0; i<=nums2.size(); i++) dp[i][0]=0;
        int ans=0;
        for(int i=1; i<=nums2.size(); i++){
            for(int j=1; j<=nums1.size(); j++){
                if(nums1[j-1]==nums2[i-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2);
    }
};