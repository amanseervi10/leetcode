//recursion
// class Solution {
// public:

//     int solve(vector<int> &cost, int index){

//         if(index>=cost.size()) return 0;

//         return min(cost[index]+solve(cost,index+1),cost[index]+solve(cost,index+2));
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(solve(cost,0),solve(cost,1));
//     }
// };


//dp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> ans(cost.size()+1);
        
        ans[2]=min(cost[0],cost[1]);

        for(int i=3; i<=cost.size(); i++){
            ans[i]=min(ans[i-2]+cost[i-2],ans[i-1]+cost[i-1]);
        }

        return ans[cost.size()];
    }
};