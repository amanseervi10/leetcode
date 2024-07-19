vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i=0,j=0,k=0;
    int store=INT_MIN;  // to store previous common element
    vector<int> ans;

    while(i<n1 && j<n2 && k<n3){
        
        if(A[i]==B[j] && B[j]==C[k] && A[i]!=store){
            ans.push_back(A[i]);
            store=A[i];
        }

        if(A[i]<=B[j] && A[i]<=C[k]) i++;
        else if(B[j]<=A[i] && B[j]<=C[k]) j++;
        else k++;
    }

    return ans;
}