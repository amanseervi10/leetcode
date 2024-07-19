vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    int i=0,j=0;
    vector<int> ans;

    while(i<n && j<m){
        if(arr1[i]>arr2[j]){
            ans.push_back(arr2[j]);
            
            do{j++;}  while(j<m && arr2[j-1]==arr2[j]);
        }
        else if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i]);

            do{i++;}  while(i<n && arr1[i-1]==arr1[i]);
        }
        else{
            ans.push_back(arr1[i]);
            do{j++;}  while(j<m && arr2[j-1]==arr2[j]);
            do{i++;}  while(i<n && arr1[i-1]==arr1[i]);
        }
    }

    while(i<n){
        ans.push_back(arr1[i]);
        do{i++;}  while(i<n && arr1[i-1]==arr1[i]);
    }
    while(j<m){
        ans.push_back(arr2[j]);
        do{j++;}  while(j<m && arr2[j-1]==arr2[j]);
    }

    return ans;
}