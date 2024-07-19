class Solution {
public:
    //recursion
    // int solve(string a, string b, int i, int j){

    //     if(j<0) return 1;
    //     if(i<0) return 0;

    //     if(a[i]==b[j]){
    //         return solve(a,b,i-1,j-1)+solve(a,b,i-1,j);
    //     }

    //     else{
    //         return solve(a,b,i-1,j);
    //     }
    // }

    //space optimized tabulation
    int numDistinct(string s, string t) {
        // return solve(s,t,s.length()-1,t.length()-1);

        int n=s.length(),m=t.length();

        vector<int> curr(m+1,0),prev(m+1,0);

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0) curr[j]=0;
                if(j==0) curr[j]=1;
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1]+prev[j];
                else curr[j]=prev[j];
            }
            prev=curr;
        }

        return prev[m];
    }
};