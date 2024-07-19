class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> store;
        for(int i=0; i<n; i++) store.insert(a[i]);

        for(int i=0; i<m; i++) store.insert(b[i]);

        return store.size();
    }
};