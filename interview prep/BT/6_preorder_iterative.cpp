//The only difference between this and then inorder iterative version is the position
//at which we push the value into the answer vector

//In this case we push it as soon as it is first found, which is how preorder works

//If this seems complex, there is also almost same method which is easy to grasp
//take a stack, into it push the root
//then pop the root , print it ans then push right child and then left child
//again pop the top item, print it ans push it's right and left child
//you can clearly see this will yield you preorder

//but i suggest try to visualize the below approach as if you do it, inorder will also 
//be automatically be done, only the printing line is shifted between the two

vector<int> preOrder(Node* root){
    
    vector<int> ans;    //to store the ans

    stack<Node*> s;

    Node* curr=root;
    while(curr!=NULL || !s.empty()){

        while(curr!=NULL){
            ans.push_back(curr->data);
            s.push(curr);
            curr=curr->left;
        }

        curr=s.top();
        s.pop();
        

        curr=curr->right;
    }
    return ans;
}