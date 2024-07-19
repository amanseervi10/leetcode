//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    if(top1+1>=top2){
        cout<<"Nah Man"<<endl;
        return;
    }
    arr[++top1]=x;
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if(top2-1<=top1){
        cout<<"Nah Man"<<endl;
        return;
    }
    arr[--top2]=x;
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1==-1) return -1;
    return arr[top1--];
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2==size) return -1;
    return arr[top2++];
}