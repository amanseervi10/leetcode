//Make clever observation that we just need to reverse the array entirely
// Next just reverse first k elemets and then rest of the array

class Solution {
public:

    void reverse(vector<int>& nums, int start, int end){
        while(end>start){
            swap(nums[start],nums[end]);
            end--; start++;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();

        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }   
};