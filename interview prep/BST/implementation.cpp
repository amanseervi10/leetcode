#include<bits/stdc++.h>
using namespace std;

struct bstnode{
    bstnode* lc=NULL;
    bstnode* rc=NULL;
    int data;
    bstnode(int k){
        data=k;
    }
};
typedef bstnode* BSTPTR;

void insert(BSTPTR& root, int val){
    if(root==NULL) root=new bstnode(val);
    
    else{
        if(val>root->data) insert(root->rc,val);
        else insert(root->lc,val);
    }
}

void inorder(BSTPTR T){
    if(T!=NULL){
        inorder(T->lc);
        cout<<T->data<<" ";
        inorder(T->rc);
    }
}

int main(){
    BSTPTR k=NULL;
    insert(k,3);
    insert(k,1);
    insert(k,5);
    insert(k,4);
    insert(k,6);
    insert(k,2);
    inorder(k);
    return 0;
}