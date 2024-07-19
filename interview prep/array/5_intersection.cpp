class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a;
        for(int i: nums1) a.insert(i);
        
        unordered_set<int> b;
        vector<int> ans;
        for(int i: nums2){
            if(a.find(i)!=a.end()) b.insert(i);
        }

        for(auto i: b){
            ans.push_back(i);
        }
        return ans;
    }
};