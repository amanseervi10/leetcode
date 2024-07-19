#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int k){
        data=k;
        right=NULL;
        left=NULL;
    }
};

void make_tree(Node* &root,int from[],int to[], int nodeCount){

    unordered_map<int, Node*> mp;
    mp[from[0]]=root;

    for(int i=0; i<nodeCount-1; i++){
        Node* temp=new Node(to[i]);
        if(mp[from[i]]->left==NULL){
            mp[from[i]]->left=temp;
        }
        else{
            mp[from[i]]->right=temp;
        }
        mp[to[i]]=temp;
    }
}

int inorder(Node* root, vector<int> &ans){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(1);
        return 1;
    }
    else{
        int temp=inorder(root->left,ans)+inorder(root->right,ans);
        ans.push_back(temp);
        return temp;
    }
}

void solve(int from[],int to[],int nodeCount){
    Node* root=new Node(from[0]);

    make_tree(root,from,to,nodeCount);

    vector<int> ans;
    inorder(root,ans);

    for(auto i : ans) cout<<i<<" ";
    cout<<endl;

    //ans vector is our answer
}

int main(){
    int from[]={1,1,1};
    int to[]={2,3,4};

    solve(from,to,4);

    return 0;
}