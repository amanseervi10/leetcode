class Solution {
public:

    //recursive
    int solve(vector<vector<char>> &matrix, int i, int j,int &mx){


        if(i<0 || j<0) return 0;

        int left=solve(matrix,i,j-1,mx);
        int top=solve(matrix,i-1,j,mx);
        int diagonal=solve(matrix,i-1,j-1,mx);

        if(matrix[i][j]=='1'){
            int k=1+min({left,top,diagonal});
            mx=max(k,mx);
            return k;
        }
        else return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        //for recursion
        // int mx=0;
        // solve(matrix,matrix.size()-1,matrix[0].size()-1,mx);

        // return mx*mx;

        //tabulation
        //It is space optimized tabulation

        int n=matrix.size(), m=matrix[0].size();
        vector<int> curr(m,0),prev(m,0);

        int mx=INT_MIN;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0) curr[j]=(matrix[i][j]=='1')?1:0;
                else if(j==0) curr[j]=(matrix[i][j]=='1')?1:0;

                else{
                    if(matrix[i][j]=='0') curr[j]=0;
                    else curr[j]=1+min({curr[j-1],prev[j],prev[j-1]});
                }

                mx=max(mx,curr[j]);
            }

            prev=curr;
        }

        return mx*mx;

    }
};