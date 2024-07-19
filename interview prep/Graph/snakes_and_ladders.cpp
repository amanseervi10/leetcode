class Solution {
public:

    //The main problem is to deal with the board. the numbering is not usual
    //we can make the board 1d

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> v;
        
        int flag=0;
        for(int i=n-1; i>=0; i--){
            if(flag){
                for(int j=n-1; j>=0; j--) v.push_back(board[i][j]);
            }
            else{
                for(int j=0; j<n; j++) v.push_back(board[i][j]);
            }
            flag=!flag;
        }

        vector<int> vis(n*n,0);
        int count=0;
        queue<int> q;
        q.push(0);  //the starting index
        vis[0]=1;

        while(!q.empty()){

            int t=q.size();
            for(int a=0; a<t; a++){
                int temp=q.front();
                cout<<temp<<" ";
                q.pop();
                if(temp>=n*n-1) return count;
    
                for(int i=1; i<=6; i++){
                    int next=temp+i;
                    if(next>=n*n) break;
    
                    if(v[next]!=-1 && !vis[v[next]-1]){
                        q.push(v[next]-1);
                        vis[v[next]-1]=1;
                    }
                    else{
                        if(!vis[next]) q.push(next);
                        vis[next]=1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};