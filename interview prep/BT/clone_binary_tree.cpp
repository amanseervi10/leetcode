//question link : https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1

//similar to clone linked list with random pointer question
//look in linked list section Q29 of 450dsa

unordered_map<Node *, Node *> mp;
Node *solve(Node *root)
{

    if (root == NULL)
        return NULL;

    Node *temp = new Node(root->data);
    mp[root] = temp;

    temp->left = solve(root->left);
    temp->right = solve(root->right);
}

void inorder(Node *root, Node *newRoot)
{
    if (root != NULL)
    {
        inorder(root->left, newRoot->left);
        newRoot->random = mp[root->random];
        inorder(root->right, newRoot->right);
    }
}

Node *cloneTree(Node *tree)
{
    unordered_map<Node *, Node *> mp;

    Node *newTree = solve(tree);
    inorder(tree, newTree);

    return newTree;
}