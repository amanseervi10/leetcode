class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;

        for(int i=1; i<arr.size()-1; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int left=i-1,right=i+1;
                while(left>=0 && arr[left]<arr[left+1]){
                    left--;
                }
                left++;
                while(right<=arr.size()-1 && arr[right]>arr[right+1]){
                    right++;
                }
                right--;
                ans=max(ans,right-left+1);
                i=right;
            }
        }

        return ans;
        
    }
};