void solve(queue<int> &q){
    if(q.empty()) return;

    int temp=q.front();
    q.pop();
    solve(q);
    q.push(temp);
}

// Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}