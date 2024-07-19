//we use heap for this
// a min heap
//the type will be pair<int,pair<int,int>>
//the first int is the element
//the first int in the pair tells use the array number while the seconod tells the index number
//in that array
typedef pair<int,pair<int,int>> cell;

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<cell,vector<cell>,greater<cell>> pq;

    for(int i=0; i<arr.size(); i++){
        pq.push({arr[i][0],{i,0}});
    }

    vector<int> ans;
    
    while(!pq.empty()){
        auto k=pq.top();
        pq.pop();

        ans.push_back(k.first);
        
        int arr_number=k.second.first;
        int arr_index=k.second.second;

        //if the array has reached it's ending then we don't need to insert it anymore
        //if not then we update accordingly
        if(arr_index<arr[arr_number].size()-1){
            int new_index=arr_index+1;
            int new_element=arr[arr_number][new_index];

            pq.push({new_element,{arr_number,new_index}});
        }
    }

    return ans;
}