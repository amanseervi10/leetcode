//Refer this : https://leetcode.com/problems/jump-game-ii/solutions/3580174/simple-o-n-time-o-1-space-solution/
//This is essentially sort of bfs
//only that we don't actually need a queue, and a variable will do

//This will work but will exeed time limit
// queue<int> q;
// q.push(0);
// int jumps=0;
// int vis[n]={0};
// vis[0]=1;

// while(!q.empty()){
    
//     int t=q.size();
    
//     for(int j=0; j<t; j++){
//         int temp=q.front();
//         q.pop();
//         if(temp==n-1) return jumps;
    
//         int k=temp+arr[temp];
//         for(int i=temp; i<=k && i<=n-1; i++){
//           if(!vis[i]) q.push(i);
//           vis[i]=1; 
//         }
//     }
//     jumps++;
// }

// return -1;


//Leetcode 

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int steps=0;
//         int max_so_far=0,max_before_next_step=0;
//         int n=nums.size();
//         int curr=0;

//         while(max_before_next_step<n-1){
//             steps++;
//             for(curr; curr<=max_before_next_step; curr++){
//                 max_so_far=max(max_so_far,curr+nums[curr]);
//                 if(max_so_far>=n-1) return steps;
//             }

//             max_before_next_step=max_so_far;
//         }
//         return steps++;
//     }
// };

//GFG
int minJumps(int arr[], int n){
    int steps=0;
    int max_so_far=0,max_before_next_step=0;
    int curr=0;
    while(max_before_next_step<n-1){
        steps++;
        for(curr; curr<=max_before_next_step; curr++){
            max_so_far=max(max_so_far,curr+arr[curr]);
            if(max_so_far>=n-1) return steps;
        }
        if(max_before_next_step==max_so_far) return -1;
        max_before_next_step=max_so_far;
    }
    return steps++;
}


//easy to understand solution
//the link at the top will help you understand it too
// int minJumps(int arr[], int n){
//         int farthest, currmax=0, jumps=0;
        
//         for(int i=0; i<n-1; i++){
//             farthest=max(farthest,i+arr[i]);
            
//             if(i>=farthest) return -1;
            
//             if(i==currmax){
//                 jumps++;
//                 currmax=farthest;
//             }
//         }
//         return jumps;
//     }