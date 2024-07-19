class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        //start from the end of the array and start to push into the stack
        //for every element keep popping until a bigger element is found
        //this element is the next greater element
        //it's kinda obvious if you visualize what exactly we are doing

        stack<long long> st;
        vector<long long> ans;

        for(int i=arr.size()-1; i>=0; i--){
            //pop until a bigger number is found
            while(!st.empty() && st.top()<=arr[i]) st.pop();

            //push into the and vector this bigger element
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());

            //push the current element
            st.push(arr[i]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};