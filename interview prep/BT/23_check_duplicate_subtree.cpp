unordered_map<int,vector<Node*>> mp;

bool check(Node* a,Node* b){
    if(a && !b) return false;
    else if(!a && b) return false;
    else if(!a && !b) return true;
    else if(a->data!=b->data) return false;
    else return (check(a->left,b->left)&check(a->right,b->right));
}

bool postorder(Node* root){
    if(root==NULL) return false;
    else if(root->left==NULL && root->right==NULL) return false;

    bool a=postorder(root->left);
    bool b=postorder(root->right);
    if(mp.find(root->data)!=mp.end()){
        int flag=0;
        for(int i=0; i<mp[root->data].size(); i++){
            if(check(root,mp[root->data][i])){
                flag=1;break;
            }
        }
        if(flag) return true;
    }
    mp[root->data].push_back(root);
    return a|b;
}

int dupSub(Node *root)
{
    return postorder(root);
}


//Alternate good solution

// unordered_map<string,int> m;
// string helper(Node* root)
// {
//     if(root==NULL)
//     return "$";
//     string s="";
//     if(root->left==NULL && root->right==NULL)
//     {
//         s=to_string(root->data);
        
//         return s;
//     }
    
    
//     s+=to_string(root->data);
//     s+=".";
    
//     s+=helper(root->left);
//     s+=".";
    
//     s+=helper(root->right);
//     s+=".";
    
//     m[s]++;
    
    
//     return s;
// }
// int dupSub(Node *root) {
//      // code here
//      m.clear();
//      helper(root);
//      for(auto i:m)
//      {
//          if(i.second>=2)
//          return true;
//      }
     
//      return false;
// }