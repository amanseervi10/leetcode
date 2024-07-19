void rotate(int arr[], int n)
{
    if(n==1) return;
    
    int i=1;
    int store=arr[0];
    do{
        int temp=arr[i];
        arr[i]=store;
        store=temp;
        i=(i+1)%n;
        
    }while(i!=1);
}