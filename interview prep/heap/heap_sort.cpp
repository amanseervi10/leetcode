// Heapify function to maintain heap property.
void heapify(int arr[], int n, int i)
{
    int left=2*i+1, right=2*i+2;
    int largest=i;

    if(left<n && arr[left]>arr[i]) largest=left;

    if(right<n && arr[right]>arr[largest]) largest=right;

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

public:
// Function to build a Heap from array.
void buildHeap(int arr[], int n)
{
    //we don't need to heapify all as i=n/2 -1 is the last element whose left or right child
    //will be in the array, beyond that it will just be out of bound

    //and btw why do we do it in reverse, as only once the subtrees as heaps can we start
    //to make the curr node follow head property
    for(int i=n/2 -1; i>=0; i--) heapify(arr,n,i);
}

public:
// Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    //we first make heap
    buildHeap(arr,n);
    
    //now above we basically made the array into a max-heap
    //so the first element of the array is the greatest, so it needs to wit at the last 
    //in the sorted array

    //so we swap it with the last element, heapify then the first element, to make sure
    //that the new element at the top is the largest and then continue
    for(int i=n-1; i>0; i--){
        swap(arr[0],arr[i]);

        //remember here that instead of the full array length, i.e n we passed i,
        //this is essentially the reduced heap as the last element is already in it's position
        //if that is also in the heap, it would eventually again get somewhere else 
        //ans no point
        heapify(arr,i,0);
    }
}