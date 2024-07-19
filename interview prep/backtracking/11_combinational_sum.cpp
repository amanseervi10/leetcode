
void solve(vector<int> &a,int index, int sum ,vector<vector<int>> &ans, vector<int> &temp){

    if(index==a.size()) return;

    if(sum==0){
        ans.push_back(temp);
        return;
    }

    if(sum>=a[index]){

        if(index>0 && a[index-1]==a[index]){
            solve(a,index+1,sum,ans,temp);
            return;
        }

        temp.push_back(a[index]);
        solve(a,index,sum-a[index],ans,temp);
        temp.pop_back();

        solve(a,index+1,sum,ans,temp);
    }

}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    sort(A.begin(),A.end());

    vector<vector<int>> ans;
    vector<int> temp;

    solve(A,0,B,ans,temp);
    return ans;
}