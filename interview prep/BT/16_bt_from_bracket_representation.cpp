//How to see this function?
//How do you begin to write it down?

// Think of it as a function in which you initially have to have the pointer at the number
// Once the number is take care of , you increment i.

//three cases are : you have no left or right child
//you have no left child
//you have no right child

//all three are discussed below

// Now after this part we want to move to the children of the current node
// Now since i was increased we should now be on a '(' for the start of a new child
// if this is not then we have a ')' instead and hence don't have a child 
// our program will get rejected by both those if conditions and increment and end that particular subtree

// let's say we had the closing bracket, now if left child is to be null, then we will have 
// a opening brace and then immediately a closing brace, hence we should return NULL in this case
// else normally recursively process that in the same manner as before

// so for this condition we need an if where our program would return NULL if character found
//is a closing brace

//lastly what if we have left child , we processed it normally, but then there is no right child
//well since out pointer was moving, when it processed the left node,
//it came out with it's pointer one step ahead of the closing brace of it's bracket,
//now if there is no right node, then we would have a closing brace in it's place for sure
//and hence we would never get into the second condition in the first place




//See this code first, below one is just an extension of this for cases where we can have 
//number greter than 10

// Node* solve(string str, int &i){
        
//         if(i>=str.length()) return NULL;
        
//         Node* root=NULL;
        
//         if(str[i]==')') return NULL;
        
//         root=new Node(str[i]-'0');
        
//         i++;
//         if(str[i]=='(') root->left=solve(str,++i);
//         if(str[i]=='(') root->right=solve(str,++i);
        
//         i++;
//         return root;
        
//     }
    
//     Node *treeFromString(string str){
//         int i=0;
//         return solve(str,i);
//     }

Node* solve(string s, int &i){
    if(i>=s.length()) return NULL;

    int num=0;
    while(s[i]>='0' && s[i]<='9'){
        num=num*10+(s[i]-'0');
        i++;
    }
    Node* root=NULL;
    if(num>0) root=new Node(num);

    if(s[i]=='(') root->left=solve(s,++i);
    
    if(s[i]=='(') root->right=solve(s,++i);

    i++;
    return root;

}

Node *treeFromString(string str)
{
    int i=0;
    return solve(str,i);
}