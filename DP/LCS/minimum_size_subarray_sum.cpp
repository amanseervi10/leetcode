class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0; int a=0;int b=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum>=target){
                b=i; break;
            }
        }
        if(sum<target) return 0;
        else{
            int ans=b+1;
            int flag=0;
            for(int b; b<nums.size(); b++){
                if(flag==1) sum+=nums[b];
                if(flag==0) flag==1;
                while(sum-nums[a]>=target){
                    sum-=nums[a]; a++;
                }
                ans=min(ans,b-a+1);
                
            }
            return ans;
        }
    }
};