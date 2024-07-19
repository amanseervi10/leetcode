// While you are at it you might wanna do this too : First missing positive number
// Solution to that : https://leetcode.com/problems/first-missing-positive/solutions/3634816/tricky/

vector<int> findTwoElement(vector<int> arr, int n)
{
    int dup=-1, missing=0;


    for(int i=0; i<n; i++){
        while(arr[i]!=i+1){
            if(arr[i]==arr[arr[i]-1]){
                dup=arr[i]; missing=i+1; break;
            }
            swap(arr[i],arr[arr[i]-1]);
        }
    }

    return {dup,missing};
}