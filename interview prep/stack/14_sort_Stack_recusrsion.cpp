void insert_at_bottom(stack<int>& s, int a){
    if(s.empty() || a>s.top()){
        s.push(a);
        return;
    }

    int temp=s.top();
    s.pop();
    insert_at_bottom(s,a);
    s.push(temp);
}

void SortedStack :: sort()
{
   if(s.empty()) return;

   int temp=s.top();
   s.pop();
   sort();
   insert_at_bottom(s,temp);
}