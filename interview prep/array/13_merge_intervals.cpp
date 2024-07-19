class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            
            vector<int> temp=ans[ans.size()-1];
            ans.pop_back();

            if(intervals[i][0]>temp[1]){
                ans.push_back(temp);
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]<=temp[1]){
                temp[1]=max(temp[1],intervals[i][1]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};