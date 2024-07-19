public:
//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
    if(low<high){
        int index=partition(arr,low,high);

        quickSort(arr,low,index);
        quickSort(arr,index+1,high);
    }
}

int getRandom(int l, int r){
        srand(time(0));
        return l + (rand() % (r - l + 1));
    }

public:
int partition(int arr[], int low, int high)
{
    int randomidx = getRandom(low, high);
    swap(arr[randomidx], arr[low]);
    int pivot=arr[low];
        int i = low - 1, j = high + 1;
        while(1){
            do{
                i++;
            }while(arr[i] < pivot);
            
            do{
                j--;
            }while(arr[j] > pivot);
            
            if(i >= j)
                return j;
            swap(arr[i], arr[j]);
        }
}