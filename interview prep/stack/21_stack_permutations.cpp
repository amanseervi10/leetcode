int isStackPermutation(int N, vector<int> &A, vector<int> &B)
{
    //to check if B is a stack permutation of A, we sort of simulate the process
    // we actually push stuff into the stack
    // a pointer is maintained at B, so whenever pushed stuff matches the pointer, it means
    //it needs to be popped now to be consistent
    //any inconsistency means it ain't no stack permutation

    //just run it through simple exmaples and you will understand

    stack<int> st;  //stack to push stuff
    int j=0;        //pointer that we gonna maintian in vector B

    for(int i=0; i<A.size(); i++){
        st.push(A[i]);
    
        while(!st.empty() && st.top()==B[j]){
            st.pop();
            j++;
        }
    }

    if(j!=B.size()) return 0;       //i.e j did not reach end of vector, i.e inconsistency
    return 1;
}