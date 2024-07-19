//Dutch National Flag Algorithm

//low here tells us the next position where we would insert 0
//mid tells the next position where we would insert 1
//high the next position where we would have 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<nums.size() && mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++; mid++;
            }
            else if(nums[mid]==1) mid++;
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;        
                //here we don't do mid++, as in first condition, we know since low is behind us,
                //it must have been processed by mid and must be only 1 and mid in it's 
                //territory needs to have 1 so it's no problemo
                //when it is swapped with high, there's a chance that it can be a 0,1 or even 2
            }
        }
    }
};