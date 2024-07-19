// class Solution {
// public:

//     int helper(vector<int> days,int n,int k){
//         int a=n;
//         while(1){
//             if(a==0) return -1;
//             else if((days[n]-days[a])>k){
//                 a++; break;
//             }
//             else a--;
//         }
//         return a;
//     }

//     int solve(vector<int> days,vector<int> costs,int n){
//         if(n==-1) return 0;
//         int a=helper(days,n,6), b=helper(days,n,29);
//         return min({costs[0]+solve(days,costs,n-1),
//                 costs[1]+solve(days,costs,a),
//                 costs[2]+solve(days,costs,b)});
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         return solve(days,costs,days.size()-1);
//     }
// };




class Solution {
public:

    int helper(vector<int> days,int n,int k){
        int a=n;
        while(1){
            if(a==-1) return -1;
            else if((days[n]-days[a])>k){
                break;
            }
            else a--;
        }
        return a;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[days.size()+1];
        dp[0]=0;
        for (int i = 1; i <=days.size(); i++){
            int a=helper(days,i-1,6),b=helper(days,i-1,29);
            dp[i]=min({costs[0]+dp[i-1], costs[1]+dp[a+1],costs[2]+dp[b+1]});
        }
        return dp[days.size()];
    }
};