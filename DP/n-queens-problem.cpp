
bool isSafe(vector<vector<int>> &board, int row,int col,int n){
    for(int i=0; i<row; i++){
        if(board[i][col]==1) return false;
    }

    int i=row-1,j=col-1;    //for upper left diagonal
    while(i>=0 && i<n && j>=0 && j<n){
        if(board[i][j]==1) return false;
        i--; j--;
    }
    i=row-1; j=col+1;
    while(i>=0 && i<n && j>=0 && j<n){
        if(board[i][j]==1) return false;
        i--; j++;
    }

    return true;
}

//solve function
void solve(int n,int curr_row,vector<vector<int>> &board,vector<int> &temp,vector<vector<int>> &ans){

    if(curr_row==n){
        ans.push_back(temp);
        return;
    }

    for(int i=0; i<n; i++){
        if(!isSafe(board,curr_row,i,n)) continue;
        temp.push_back(i+1);
        board[curr_row][i]=1;
        solve(n,curr_row+1,board,temp,ans);
        board[curr_row][i]=0;
        temp.pop_back();
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    vector<int> temp;

    solve(n,0,board,temp,ans);
    return ans;
}