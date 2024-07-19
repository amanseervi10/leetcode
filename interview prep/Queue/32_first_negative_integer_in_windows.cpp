//There are three problems of this kind, this one being the easiest of them, as it can be done
//using a subset of steps of the harder ones

//The other are : find maximum/minimum/both in window of given size
//Another problem which can be thought of being in same category due to its use of queue,
//althought the algo is different is "36_finding first non repeating character in stream"

//anyways see this article : https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    queue<long long> q;   //this stores indices of the elements which are negative and in the current window
    vector<long long> ans;

    long long i=0;
    for(i; i<K; i++){           //We first push the indices of the neative elements in first K positions
        if(A[i]<0) q.push(i);
    }
    if(q.empty()) ans.push_back(0);
    else ans.push_back(A[q.front()]);
    

    for(i; i<N; i++){
        if(!q.empty() && q.front()<=i-K){
            q.pop();
        }
        if(A[i]<0) q.push(i);

        if(q.empty()) ans.push_back(0);
        else ans.push_back(A[q.front()]);
    }

    return ans;
}