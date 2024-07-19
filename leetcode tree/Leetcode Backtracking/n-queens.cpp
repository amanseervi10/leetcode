class Solution {
public:

    vector<vector<string>> ans;

    void flip(vector<vector<int>>& arr, int row, int column, int n){
        for(int i=0; i<n; i++) if(arr[row][i]!=2) arr[row][i]=-1;
        for(int i=0; i<n; i++) if(arr[i][column]!=2) arr[i][column]=-1;
        int curr_row=row+1, curr_column=column+1;
        while(curr_row>=0 && curr_row<n && curr_column>=0 && curr_column<n){
            arr[curr_row][curr_column]=-1;
            curr_row++; curr_column++;
        }
        curr_row=row-1, curr_column=column-1;
        while(curr_row>=0 && curr_row<n && curr_column>=0 && curr_column<n){
            arr[curr_row][curr_column]=-1;
            curr_row--; curr_column--;
        }
        curr_row=row+1, curr_column=column-1;
        while(curr_row>=0 && curr_row<n && curr_column>=0 && curr_column<n){
            arr[curr_row][curr_column]=-1;
            curr_row++; curr_column--;
        }
        curr_row=row-1, curr_column=column+1;
        while(curr_row>=0 && curr_row<n && curr_column>=0 && curr_column<n){
            arr[curr_row][curr_column]=-1;
            curr_row--; curr_column++;
        }
    }


    void solve(int n, int i,int prev_row,vector<vector<int>> arr){

        if(i!=0) flip(arr,prev_row,i-1,n);

        if(i==n){
            vector<string> temp;
            for(int j=0; j<n; j++){
                string s="";
                for(int l=0; l<n; l++){
                    if(arr[j][l]==0) s+='.';
                    if(arr[j][l]==-1) s+='.';
                    if(arr[j][l]==2) s+='Q';
                }  
                temp.push_back(s); 
            }
            ans.push_back(temp);
            return;
        }

        for(int j=0; j<n; j++){
            if(arr[j][i]==-1) continue;
            arr[j][i]=2;
            cout<<"yes"<<endl;
            solve(n,i+1,j,arr);
            arr[j][i]=0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> arr;
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=0;j<n; j++) temp.push_back(0);
            arr.push_back(temp);
        }
        solve(n,0,-1,arr);
        return ans;
    }
};