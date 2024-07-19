//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

// Create a Deque, Qi of capacity K, that stores only useful elements of current window of K 
// elements. An element is useful if it is in current window and is greater than all other elements
// on right side of it in current window. Process all array elements one by one and 
// maintain Qi to contain useful elements of current window and these useful elements 
// are maintained in sorted order. The element at front of the Qi is the largest and 
// element at rear/back of Qi is the smallest of current window.

//What the above approach will essentially do is kinda that we will only keep elements
//if it still will get printed as max element of a window. if it's out of the the reach of 
//the window i.e q.front()<=i-k, then we remove it
//else we keep printing that, ans since the queue itself is always sorted , when that element 
//pops out, it's the next greatest element that become the new queue front.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};    //array
    int k = 3;   //windows size
    vector<int> ans;

    //we will use a queue based approach

    deque<int> q;
    int i=0;
    for(i; i<k; i++){
        while(!q.empty() && arr[q.back()]<=arr[i]) q.pop_back();
        q.push_back(i);
    }
    ans.push_back(arr[q.front()]);

    for(i; i<9; i++){
        if(!q.empty() && q.front()<=i-k) q.pop_front();

        while(!q.empty() && arr[q.back()]<=arr[i]) q.pop_back();
        q.push_back(i);
        ans.push_back(arr[q.front()]);
    }

    for(auto k : ans) cout<<k<<" ";
    cout<<endl;
    return 0;
}



//Below is for gfg question on the same pattern - IPL 2021-Match Day 2

vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
    vector<int> ans;
    deque<int> q;

    int i=0;
    for(i; i<k; i++){
        while(!q.empty() && arr[q.back()]<=arr[i]) q.pop_back();
        q.push_back(i);
    }
    ans.push_back(arr[q.front()]);

    for(i; i<n; i++){
        if(!q.empty() && q.front()<=i-k) q.pop_front();

        while(!q.empty() && arr[q.back()]<=arr[i]) q.pop_back();
        q.push_back(i);

        ans.push_back(arr[q.front()]);
    }

    return ans;
}