int solve(int arr1[],int arr2[],int start1,int start2,int k,int m,int n){

    if(start1==n){
        // cout<<1<<" ";
        return arr2[start2+k-1];
    }
    if(start2==m){ 
        // cout<<2<<" ";
        return arr1[start1+k-1];
    }

    if(k==1) {
        // cout<<3<<" ";
        return min(arr1[start1],arr2[start2]);
    }

    int p=k/2;
    if(start1+p-1>n-1){
        // cout<<4<<" ";
        if(arr1[n-1]<arr2[start2+p-1]){
            // cout<<10<<" ";
            return arr2[start2+(k-(n-1-start1+1))-1];
        }
        else {
            // cout<<8<<" ";
            return solve(arr1,arr2,start1,start2+p,k-p,m,n);
        }
    }
    else if(start2+p-1>m-1){
        // cout<<5<<" ";
        if(arr2[m-1]<arr1[start1+p-1]){
            // cout<<11<<" ";
            return arr1[start1+(k-(m-1-start2+1))-1];
        }
        else{
            // cout<<9<<" ";
            return solve(arr1,arr2,start1+p,start2,k-p,m,n);
        }
    }

    if(arr1[start1+p-1]>arr2[start2+p-1]){
        // cout<<6<<" ";
        return solve(arr1,arr2,start1,start2+p,k-p,m,n);
    }
    else{ 
        // cout<<7<<" ";
    return solve(arr1,arr2,start1+p,start2,k-p,m,n);}
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    return solve(arr1,arr2,0,0,k,m,n);
}