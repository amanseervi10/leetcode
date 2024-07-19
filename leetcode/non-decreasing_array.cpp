class Solution {
public:

    bool helper(vector<int>& nums){
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }

    bool checkPossibility(vector<int>& nums) {
        int flag=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                int a=nums[i],b=nums[i-1];
                nums[i]=b;
                if(helper(nums)) return true;
                else {
                    nums[i-1]=a; nums[i]=a;
                    if(helper(nums)) return true;
                    else return false;
                }
            }
        }
        return true;
    }
};