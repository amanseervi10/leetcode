bool isMaxHeap(int a[], int n)
{
    for(int i=0; i<n; i++){
        int left=2*i+1,right=2*i+2;

        if(left>n-1) break;
        if(a[left]>a[i]) return false;

        if(right>n-1) break;
        if(a[right]>a[i]) return false;
    }

    return true;
}