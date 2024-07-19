class Solution {
public:

    int dp[1001][1001];
    string solve(string nums1,string nums2){
        for(int i=0; i<=nums1.length(); i++) dp[0][i]=0;
        for(int i=0; i<=nums2.length(); i++) dp[i][0]=0;
        int maxlength=0;
        string ans="";
        for(int i=1; i<=nums2.length(); i++){
            for(int j=1; j<=nums1.length(); j++){
                if(nums1[j-1]==nums2[i-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>maxlength){
                        maxlength=dp[i][j];
                        string temp="";
                        int k=i;
                        int q=maxlength;
                        while(q--){
                            temp=nums2[k-1]+temp;
                            k--;
                        }
                        ans=temp;
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        cout<<maxlength<<endl;
        return ans;
    }

    string longestPalindrome(string s) {
        string k=s;
        reverse(k.begin(),k.end());
        return solve(s,k);
    }
};