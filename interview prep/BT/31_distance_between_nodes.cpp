class Solution{
    public:
    int travel(Node* root,int a, int b, int level){
    if(root==NULL) return -1;
    
    int x=travel(root->left,a,b,level+1);
    int y=travel(root->right,a,b,level+1);

    if(root->data==a && root->data==b) return 0;
    if(root->data==a || root->data==b){
        if(x!=-1 || y!=-1){
            return ((x==-1)?y:x)-level;
        }
        else return level;
    }   
    else if(x!=-1 && y!=-1) return (x+y-2*level);
    else if(x!=-1 || y!=-1) return (x==-1)?y:x;
    return -1;
}

int findDist(Node *root, int a, int b)
{
    return travel(root,a,b,0);
}
};