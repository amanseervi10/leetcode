// 1 2 3 4 5
// 1 2 3 5 4    //here 5 4 are in reverse, so in next cycle 3 gets affected, this is how it works
// 1 2 4 3 5
// 1 2 4 5 3
// 1 2 5 3 4
// 1 2 5 4 3    //here 5 4 3 are in complete reverse, so in next permutation a new element will get affected, i.e 2
// 1 3 2 4 5        

//so we first find out the point up till we have perfect reverse
//this can be done by simply checking if arr[i]<arr[i+1] at a point

//next we know that the smallest next bigger element should come in the to the point of change
//like in the last line 2 was replaced by 3,after more cycle we will reach at 1 3 5 4 2
//after this point 4 should come to the point of change, which is smallest next bigger element

//so we swap these two, i.e 3 and 4
//this will not change the fact that the last 3 elements are still in reverse, they need be
//opposite of this
//so we simply reverse the array after the point of change

vector<int> nextPermutation(int n, vector<int> arr)
{
    int index=-1;   //point of change
    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }

    for(int i=n-1; i>=index && index!=-1; i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr.begin()+index+1,arr.end());
    return arr;
}