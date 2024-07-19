//https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
//above has approach to solve in O(1) time / O(n) space as well as O(1) time/O(1) space
//versions. The latter though only applicable if the nature of the data is known
//Here we won't even apply the first onw though as for that we need to alter the structure
//of a stack, but we have already been given the stl stack.
//This method is O(N) time/O(N) space ans is recursive in nature



void push(stack<int>& s, int a){
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n) return true;
    return false;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	int temp=s.top();
    s.pop();
    return temp;
}

int getMin(stack<int>& s){
    if(s.empty()) return 10000000;
	int a=s.top();
    s.pop();
    int b=getMin(s);
    s.push(a);
    return min(a,b);
}