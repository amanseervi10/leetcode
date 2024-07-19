// https://www.geeksforgeeks.org/the-celebrity-problem/
// do refer above link
// all efficient ones use essentially same logic, but have slight different implementation
//below i use two pointer approach

//basically for every two person A and B, if A knows B, A can't be celebrity, else B can't be celebrity

//return wheather i knows j
bool knows(vector<vector<int>> &M,int i, int j){
    if(M[i][j]==1) return true;
    return false;
}

int celebrity(vector<vector<int>> &M, int n)
{
    int i=0,j=n-1;
    while(j>i){
        if(knows(M,i,j)) i++;   //as then i can't be celebrity
        else j--;              //as then j can't be celebrity
    }

    //now we check for the one person remaining if he is known by all
    for(int k=0; k<n; k++){
        if(k==j) continue;
        else{
            if(M[k][j]==0 || M[j][k]==1) return -1;
        }
    }
    return j;
}