class Solution {
public:

    int binary_search(vector<vector<int>>& matrix, int key){
        int start=0,end=matrix.size()-1;
        while(end>start){
            int mid=(start+end)/2;
            if(matrix[mid][0]==key) return mid;
            else if(matrix[mid][0]>key) end=mid-1;
            else start=mid+1;
            if(key>matrix[mid][0] && key<matrix[mid+1][0]) return mid;
        }
        return start;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_number=binary_search(matrix,target);
        cout<<row_number<<endl;
        auto iterator=lower_bound(matrix[row_number].begin(),matrix[row_number].end(),target);
        if(iterator==matrix[row_number].end()) return false;
        else if(*iterator!=target){
            // cout<<*iterator<<endl;
            return false;
        }
        return true;
    }
};