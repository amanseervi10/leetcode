void solve(queue<int> &q, int target){
    if(target==0) return;
    
    int temp=q.front();
    q.pop();
    solve(q,--target);
    q.push(temp);
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    solve(q,k);
    for(int i=0; i<q.size()-k; i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}