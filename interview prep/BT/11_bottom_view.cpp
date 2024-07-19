//between this and the topView problem, i literally changed just the sign of the comparison
//operator in the if condition in preorder function

//note: it's greater than equal to and not equal to as the question said that, that the one
//which comes later in the traversal need to be given priority if two nodes are at same 
//x-coordinate and height(or depth)

map<int,pair<int,int>> s;

void preorder(Node* root,int k,int height){
    if(root!=NULL){
        if(s.find(k)==s.end() || height>=s[k].second){
            s[k]={root->data,height};
        }
        preorder(root->left,k-1,height+1);
        preorder(root->right,k+1,height+1);
    }
}

vector<int> bottomView(Node *root)
{
    preorder(root,0,0);
    vector<int> ans;
    for(auto it: s){
        ans.push_back(it.second.first);
    }
    return ans;
}