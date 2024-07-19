class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> positive,negative;
        for(int i=0; i<n; i++){
            if(arr[i]>=0) positive.push_back(arr[i]);
            else negative.push_back(arr[i]);
        }
        int curr=0;
        for(int i=0; i<positive.size(); i++){
            arr[curr]=positive[i];
            curr++;
        }
        for(int i=0; i<negative.size(); i++){
            arr[curr]=negative[i];
            curr++;
        }
    }
};