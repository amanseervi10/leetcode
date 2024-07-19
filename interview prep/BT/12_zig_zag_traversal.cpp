 vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);

    //the flag which will change after every level is traversed
    int flag=0;

    while(!q.empty()){
        int k=q.size();
        vector<int> a;
        for(int i=0; i<k; i++){
            Node* temp=q.front();
            q.pop();
            a.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

            
        }
        //reversing if the flag says so
        if(flag) reverse(a.begin(),a.end());

        for(auto it: a) ans.push_back(it);

        flag=!flag;
    }
    return ans;
}