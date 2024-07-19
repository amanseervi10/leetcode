int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int> store;
    for(int i=0; i<N; i++){
        store.insert(arr[i]);
    }

    int ans=0;

    for(auto i : store){
        if(store.find(i-1)==store.end()){  // logic for this below - *1
            int temp=1,curr=i+1;
            while(store.find(curr)!=store.end()){
                temp++; curr++;
            }
            ans=max(ans,temp);
        }
    }

    return ans;
}

//  *1 -> So that we only start from a value which is starting point of some possible subsequece
// for example -> 3 2 1 4 5
// when we encounter 3 we won't do anything as there is a value before 3 i.e 2 which 
//only makes it difficult for us to search(we will have to search in both directions)

// instead if we skip 3 and 2, we get to 1 which has nothing before it and hence is start
// of a subsequence