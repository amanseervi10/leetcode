#include<bits/stdc++.h>
using namespace std;

struct node{
    node* right;
    node* left;
    int val;
    node(int k){
        val=k;
        left=NULL;
        right=NULL;
    }
};

void tree_make(node* root, int val, string s){
    
    int n=s.length();
    node* temp=root;

    for(int i=0; i<n-1; i++){
        if(s[i]=='L') temp=temp->left;
        else temp=temp->right;
    }

    if(s[n-1]=='L') temp->left=new node(val);
    else temp->right=new node(val);
}

void solve(node* root, int &ans)
{
    if(!root)
        return;

    if(root->left && root->right)
    {
        int a=root->left->val;
        int b=root->right->val;

        if(a%b==0 || b%a==0)
            ans+=root->val;
    }

    solve(root->left, ans);
    solve(root->right, ans);
}

int magicParentSum(int N,int root,string pos[],int val[]){

    node* head=new node(root);

    for(int i=0; i<N-1; i++){
        tree_make(head,val[i],pos[i]);
    }

    int ans=0;
    solve(head,ans);

    if(ans==0) return -1;
    else return ans;

}

int main(){
    string pos[]={}
    return 0;
}