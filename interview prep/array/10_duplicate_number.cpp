//https://leetcode.com/problems/find-the-duplicate-number/solutions/1892921/9-approaches-count-hash-in-place-marked-sort-binary-search-bit-mask-fast-slow-pointers/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

//See these questions and solution also : 
//https://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
//https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
