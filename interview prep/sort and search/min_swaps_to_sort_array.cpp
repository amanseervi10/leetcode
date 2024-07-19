 //Function to find the minimum number of swaps required to sort the array. 
	// refer : https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/

int minSwaps(vector<int> &nums)
{
    vector<pair<int,int>> arr;
    for(int i=0; i<nums.size(); i++){
        arr.push_back({nums[i],i});
    }

    sort(arr.begin(),arr.end());

    int ans=0;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i].second==-1 || arr[i].second==i) continue;

        int count=0;
        int k=i;
        while(arr[k].second!=-1){
            int temp=k;
            k=arr[k].second;
            arr[temp].second=-1;
            
            count++;
        }
        ans+=count-1;
    }
    return ans;
}