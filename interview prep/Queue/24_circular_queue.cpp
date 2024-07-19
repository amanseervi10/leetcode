//This is some question from KR sir
//but use this as inspiration for structure of queue also

#include<iostream>
using namespace std;

struct operation{
    int x,y;
    char ch;
};

struct queue{
    int s,f,r;
    operation *elements;
    queue(int x){
        s=x;
        f=-1;
        r=-1;
        elements=new operation[x];
    }
    void enque(operation x){
        if((r+1)%s==f){
            return;
        }
        else if(r==-1){
            r=0;f=0;
        }
        else{
            r=(r+1)%s;
        }
        elements[r]=x;
    }
    operation deque(){
        operation o;
        if(f==-1){
            return o;
        }
        else{
            operation t=elements[f];
            if(f==r){
                f=-1;r=-1;
            }
            else{
                f=(f+1)%s;
            }
            return t;
        }
    }
};

int calculate(operation O){
    if(O.ch=='A'){
        return O.x+O.y;
    }
    else if(O.ch=='S'){
        return O.x-O.y;
    }
    else{
        return O.x*O.y;
    }
}

int main(){
    queue q(20);
    operation n;
    cin>>n.x>>n.y>>n.ch;
    int i=0;
    while(n.x!=-1){
        q.enque(n);
        i++;
        cin>>n.x>>n.y>>n.ch;
    }
    for(int j=0; j<i; j++){
        cout<<calculate(q.deque())<<endl;
    }
    return 0;
}