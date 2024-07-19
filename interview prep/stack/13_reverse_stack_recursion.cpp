//The below solution is O(N^2) in time and O(N) in space
//GFG expected time complexity is wrong
//https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

void insert_at_bottom(stack<int> &St, int a){
    if(St.empty()){
        St.push(a);
        return;
    }

    int temp=St.top();
    St.pop();
    insert_at_bottom(St,a);
    St.push(temp);  
}

void Reverse(stack<int> &St)
{
    if(St.empty()) return;
    
    int temp=St.top();
    St.pop();
    Reverse(St);
    insert_at_bottom(St,temp);
}