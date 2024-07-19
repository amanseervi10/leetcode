//refer : https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

//we can use a map based method or a queue based method
//i am using the queue based method as it is more efficient

vector<int> diagonal(Node *root)
{
    vector<int> ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int k=q.size();

        for(int i=0; i<k; i++){
            auto temp=q.front();
            q.pop();

            while(temp!=NULL){
                if(temp->left) q.push(temp->left);

                ans.push_back(temp->data);
                temp=temp->right;
            }
        }
    }

    return ans;
}