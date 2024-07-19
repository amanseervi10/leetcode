// so what is our approach?
// think of it like this, we add k into some elements and sibtract it from some other elements

//now it is obvious that we add k in the smaller elements and subtract from the greater elements
//but what exactly should be the threshold for this addition, what is that number beyond which
//we should subtract and below which we should add

//so we sort the array and traverse it from 1, (we obviously add to the smallest element)

//we are trying to find the boundary in the array, the place we stop adding and start subtracting
//at every point we treat the current element as it is the first one from which we subtract(if we can subtract ofcourse)

//so at every point we see what would be the possible min and max if this were indeed to be the boundary
//and according to this we choose a boundary and update our answer

//the curr_min and curr_max calculation at every index are fairly obvious

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
      sort(arr,arr+n);

      int ans=arr[n-1]-arr[0];

      for(int i=1; i<n; i++){
        if(arr[i]<k) continue;

        int curr_min=min(arr[0]+k,arr[i]-k);
        int curr_max=max(arr[n-1]-k,arr[i-1]+k);

        ans=min(ans,curr_max-curr_min);
      }

      return ans;
    }
};