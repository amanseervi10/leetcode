void path(Node* root, vector<Node*> &store,int target){
    if(root!=NULL){
        store.push_back(root);
        if(root->data==target) return;

        path(root->left,store,target);

        if(store[store.size()-1]->data==target) return;

        path(root->right,store,target);
        if(store[store.size()-1]->data==target) return;
        store.pop_back();
    }
}



int minTime(Node *root, int target)
{
    vector<Node*> store;
    path(root,store,target);
    

    int time=-1;
    int j=store.size()-1;

    queue<Node*> q;
    q.push(store[j]);
    j--;

    unordered_set<Node*> vis;

    while(!q.empty()){
        int k=q.size();


        for(int i=0; i<k; i++){
            Node* temp=q.front();
            q.pop();
            vis.insert(temp);
            

            if(temp->left && !vis.count(temp->left)) q.push(temp->left);
            if(temp->right && !vis.count(temp->right)) q.push(temp->right);
        }
        if(j>=0){
            q.push(store[j]);
            j--;
        }
        time++;
    }

    return time;
}