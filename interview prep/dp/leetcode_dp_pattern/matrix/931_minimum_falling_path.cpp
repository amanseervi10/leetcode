class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> curr(m,0),prev(m,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(i==0) curr[j]=matrix[i][j];

                else{
                    int top=INT_MAX,left=INT_MAX,right=INT_MAX;

                    if(j-1>=0) left=prev[j-1];
                    if(j+1<m) right=prev[j+1];
                    top=prev[j];

                    curr[j]=matrix[i][j]+min({top,left,right});
                }
            }

            prev=curr;
        }

        int mn=INT_MAX;
        for(int i=0; i<m; i++) mn=min(mn,prev[i]);

        return mn;
    }
};