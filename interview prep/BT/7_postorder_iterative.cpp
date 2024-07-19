//can do it with two stacks (which is fairly easy)
//just do preorder iterative with two exeptions : 
// 1. instead of printing you push stuff into another stack
// 2. preorder is node/left/right , but you do it in node/right/left

//when from the second stack you pop items, they will be in postorder

//below is how to do it using a single stack
//refer : https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
//see the second method in there, not the first one

//basically you have no problem pushing both root and root->right
//but how you gonna know that the node popped out has it's child yet to be processed
//for that instead of pushing root and root->right, we push root ans root
//so if after popping stack top is still root, means you gotta dig in this node popped node
//ans else you gotta    print this found node

//rest remains same as preorder and shit

vector<int> postOrder(Node *node)
{
    vector<int> ans;
    stack<Node*> s;

    while(1){
        while(node!=NULL){
            s.push(node);
            s.push(node);
            node=node->left;
        }

        if(s.empty()) break;

        node=s.top();
        s.pop();
        if(!s.empty() && s.top()==node){
            node=node->right;
        }
        else{
            ans.push_back(node->data);
            node=NULL;  //as if you printed stuff means a subtree it over, and 
            //this child node has been finished, and now you'll move to the other child
        }
    }

    return ans;
}