#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
//We gotta use doubly linked list for this

class stm{
    struct node{
        node* next;
        node* prev;
        int data;

        node(int x){
            data=x;
            next=NULL;
            prev=NULL;
        }
    };

    node* head=NULL;
    node* middle=NULL;
    int size=0;

    public :
    void push(int x){
        if(size==0){
            head=new node(x);
            middle=head;
            size++;
        }
        else{
            size++;
            head->next=new node(x);
            head->next->prev=head;
            head=head->next;
            if(size%2==1) middle=middle->next;
        }
    }

    int pop(){
        if(size==0) return -1;
        int temp=head->data;
        if(size==1){
            head=NULL;
            middle=NULL;
            size=0;
        }
        else{
            size--;
            head=head->prev;
            head->next=NULL;
            if(size%2==0) middle=middle->prev;
        }
        return temp;
    }

    int findMiddle(){
        if(middle==NULL) return -1;
        else return middle->data;
    }

    void deleteMiddle(){
        if(middle==NULL) return;     //size is 0
        else if(size==1){           //size is 1
            head=NULL;
            middle=NULL;
        }
        else if(size==2){
            middle=head;
            head->prev=NULL;
        }
        else{
            middle->prev->next=middle->next;
            size--;
            if(size%2==0) middle=middle->prev;
            else middle=middle->next;
        }
    }
};

int main(){
    cout<<"yes"<<endl;
    stm st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout<<"yes"<<endl;
    cout <<"Middle Element : "<< st.findMiddle() << endl;
    st.deleteMiddle();
    cout <<"New Middle Element : "<< st.findMiddle() << endl;
    return 0;
}