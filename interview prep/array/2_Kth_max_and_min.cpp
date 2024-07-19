// class Solution {
// public:

//     int partition(vector<int>& arr,int left,int right){
//         int pivot=arr[right],i=left-1;
//         for(int j=left; j<=right-1; j++){
//             if(arr[j]<=pivot){
//                 i++;
//                 int temp=arr[i];
//                 arr[i]=arr[j]; arr[j]=temp;
//             }
//         }
//         arr[right]=arr[i+1];
//         arr[i+1]=pivot;
//         return i+1;
//     }

//     int solve(vector<int>& arr,int left,int right, int k){
        
//         int curr=partition(arr,left,right);

//         if(curr-left+1==k) return arr[curr];
//         else if(curr-left+1>k){
//             return solve(arr,left,curr-1,k);
//         }
//         else{
//             return solve(arr,curr+1,right,k-(curr-left+1));
//         }
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         return solve(nums,0,nums.size()-1,nums.size()-k+1);
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        for(int i=0; i<k-1; i++){
            pq.pop();
        }
        return pq.top();
    }
};