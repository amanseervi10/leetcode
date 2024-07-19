class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        int count=1;
        int totalElements=n*n;
        int startRow=0,startCol=0;
        int endRow=n-1,endCol=n-1;
        int curr=1;

        while(count<=totalElements){
            for(int i=startCol; i<=endCol && count<=totalElements; i++){
                ans[startRow][i]=count;
                count++;
            }
            startRow++;

            for(int i=startRow; i<=endRow && count<=totalElements; i++){
                ans[i][endCol]=count;
                count++;
            }
            endCol--;

            for(int i=endCol; i>=startCol && count<=totalElements; i--){
                ans[endRow][i]=count;
                count++;
            }
            endRow--;
            
            for(int i=endRow; i>=startRow && count<=totalElements; i--){
                ans[i][startCol]=count;
                count++;
            }
            startCol++;
        }
        return ans;
    }
};