//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1322101/c-java-python-maxheap-minheap-binary-search-picture-explain-clean-concise/


class Solution
{
public:
    struct Compare{
        bool operator()(vector<int> const &a, vector<int> const &b){
            return a[0] > b[0];
        }
    };

    int kthSmallest(vector<vector<int>> &matrix, int k){
        //Making priority queue of vectors
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        //First element of vector is the elements, second is the row number,
        //third is the column number
        for (int i = 0; i < matrix.size(); i++){
            vector<int> temp={matrix[i][0],i,0};
            pq.push(temp);
        }

        for(int i=0; i<k-1; i++){
            vector<int> temp=pq.top();
            pq.pop();
            temp[2]++;  //updating the colum
            if(temp[2]==matrix[0].size()) continue;   //if it's reached the end of column
            else{
                temp[0]=matrix[temp[1]][temp[2]];    //else updating it with next element of column
                pq.push(temp);                       //pushing updated vector
            }
        }

        vector<int> temp=pq.top();
        return temp[0];
    }
};

// https://stackoverflow.com/questions/48840649/constructing-a-priority-queue-of-vectors