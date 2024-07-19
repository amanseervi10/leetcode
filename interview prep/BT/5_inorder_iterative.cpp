//Refer the below link
//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

//NOTE : 
// There are 3 main approaches to do tree traversal,
// 1. Recursive - O(N) Time/ O(H) Space (for recursion stack)
// 2. Iterative - O(N) Time/ O(H) Space (using explicit stack)
// 3. Morris Traversal - O(N) Time/ O(1) Space (uses theaded binary tree)

//Look into this morris traversal as it it pretty intuitive

vector<int> inOrder(Node* root){
    
    vector<int> ans;    //to store the ans

    stack<Node*> s;

    Node* curr=root;
    while(curr!=NULL || !s.empty()){

        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }

        curr=s.top();
        s.pop();
        
        ans.push_back(curr->data);

        curr=curr->right;
    }
    return ans;
}