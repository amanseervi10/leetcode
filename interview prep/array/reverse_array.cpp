
void reverse(int arr[],int start, int end){
    while(end>start){
        swap(arr[start],arr[end]);
        start++; end--;
    }
}

void leftRotate(int arr[], int n, int d)
{
    d=d%n;

    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

//if required to reverse in clockwise direction we can do same thing from back side
//i.e
//reverse(arr,n-1-(d-1),n-1);
//reverse(arr,0,n-1-(d-1)-1);
//reverse(arr,0,n-1);