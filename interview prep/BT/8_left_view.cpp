//This is the method using queue, but there is another very good method using recursion
//See the rightview solution, i did it the other way

vector<int> leftView(Node *root)
{
    vector<int> ans;
    queue<Node*> q; 
    if(root==NULL) return ans;
    q.push(root);
    while(!q.empty())   {
        int k=q.size();
        int flag=0;
        for(int i=0; i<k; i++){
            Node* temp=q.front();
            if(!flag){
                ans.push_back(temp->data);
                flag=1;
            }
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}
