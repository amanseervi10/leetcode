// Function to insert heap.

//we esentially create a max and a min heap
//the max heap contains the first half elements, while the min heap contains the second half elements
// that wayy at any point we have the middle elements as the top elements of the two heaps

priority_queue<int> mx; //max heap
priority_queue<int,vector<int>,greater<int>> mn;    //min heap

void insertHeap(int &x)
{
    if(mx.empty() && mn.empty()) mx.push(x);    //if empty then we push in max heap
    else if(x<mx.top()) mx.push(x);
    else mn.push(x);

    balanceHeaps();
}

// Function to balance heaps.
void balanceHeaps()
{
    //we will try to balance in such a way that either both have same size or max-heap is bigger
    //note that we will make sure that size differene between them is not more than 1
    //The above will help us ensure that the median is the top element of max heap
    //if number of elements is odd and average of the top of the two otherwise

    //if min heap (i.e second half) is bigger we take it from there and transfer to max heap
    //also since we are constanly checking after every insertion, the size difference can never
    //be more than 1 hence only 1 element is being moved
    if(mn.size()>mx.size()){
        mx.push(mn.top());
        mn.pop();
    }

    //we make them of equal size
    else if(mx.size()-mn.size()==2){
        mn.push(mx.top());
        mx.pop();
    }
}

// Function to return Median.
double getMedian()
{
    if((mn.size()+mx.size())%2==0){
        return (mn.top()+mx.top())*1.0/2;
    }
    else return mx.top();
}