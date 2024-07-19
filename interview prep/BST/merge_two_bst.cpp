//class which gives element in inorder traversal in o(h) space.
class BSTIterator{
    
    private:
        stack<Node*>st;
    
    public:
        BSTIterator(Node* root){
            push_all(root);
        }
        //return if more elements are left in tree traversal or not.
        bool hasnext(){
            return !st.empty();
        }
        //return the next item in inorder traversal.
        int getItem(){
            Node* temp=st.top();
            st.pop();
            
            if(temp->right){
                push_all(temp->right);
            }
            return temp->data;
        }
        
        void push_all(Node* root){
            
            while(root){
                st.push(root);
                root=root->left;
            }
        }
        
};       


class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int>ans;
       
       BSTIterator bst1(root1);
       
       BSTIterator bst2(root2);

       int a=bst1.getItem();
       int b=bst2.getItem();
       while(true){
           if(a<=b){
               ans.push_back(a);
               if(bst1.hasnext()){
                   a=bst1.getItem();
                   
               }
               else{
                   ans.push_back(b);
                   break;
               } 
           }
           else{
               ans.push_back(b);
               if(bst2.hasnext()){
                   b=bst2.getItem();
                   
               }
               else{
                   ans.push_back(a);
                   break;
               } 
           }
       }
       
       while(bst1.hasnext()){
           ans.push_back(bst1.getItem());
       }
       
       while(bst2.hasnext()){
           ans.push_back(bst2.getItem());
       }
       
       return ans;
       
    }
};