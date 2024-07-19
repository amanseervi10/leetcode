class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0;
        int mn=INT_MAX;
        
        int curr_sum=nums[0];

        while(1){
            if(curr_sum<target){
                end++;
                if(end==nums.size()) break;
                curr_sum+=nums[end];
            }
            else if(curr_sum>=target){
                mn=min(mn,end-start+1);
                cout<<start<<" "<<end<<endl;
                curr_sum-=nums[start];
                start++;
                if(start==end && curr_sum>=target){
                    mn=1; break;
                }
            }
        }

        if(mn==INT_MAX) return 0;
        else return mn;
    }
};