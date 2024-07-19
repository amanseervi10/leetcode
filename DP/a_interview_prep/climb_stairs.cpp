//recursion
class Solution {
public:

    int solve(int n){

        if(n<0) return;
        else if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 2;

        return (solve(n-1)+solve(n-2));
    }


    int climbStairs(int n) {
        return solve(n);
    }
};

//dp
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;

        int ans[n+1];
        ans[1]=1; ans[2]=2;
        for(int i=3; i<=n; i++){
            ans[i]=ans[i-1]+ans[i-2];
        }

        return ans[n];
    }
};