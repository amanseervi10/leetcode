int search(int arr[], int n, int x, int k)
{
    int i=0;
    while(i<n){
        if(arr[i]==x) return i;     //if you found it, return it

        //since every adjacent element differ by atmost k, we can confidently say that 
        //our desired element in this situation (i.e x-arr[i]>k) won't be found
        //fpr any i less that this(see below)
        else if(x-arr[i]>k) i+=(x-arr[i])/k;    
        else i++;
    }
    return -1;
}