class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int count=0;
        int totalElements=matrix[0].size()*matrix.size();
        int startRow=0,startCol=0;
        int endRow=matrix.size()-1,endCol=matrix[0].size()-1;
        vector<int> ans;

        while(count<totalElements){
            for(int i=startCol; i<=endCol && count<totalElements; i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            for(int i=startRow; i<=endRow && count<totalElements; i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int i=endCol; i>=startCol && count<totalElements; i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            
            for(int i=endRow; i>=startRow && count<totalElements; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }

        return ans;
    }
};