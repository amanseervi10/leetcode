// problem link : https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//Refer this :  https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

TNode* solve(LNode* &head, int n){

    if(n<=0) return NULL;

    TNode* left_subtree=solve(head,n/2);

    TNode* root=new TNode(head->data);
    head=head->next;

    TNode* right_subtree=solve(head,n-(n/2 + 1));

    root->left=left_subtree;
    root->right=right_subtree;

    return root;
}

int count(LNode* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

TNode *sortedListToBST(LNode *head)
{
    int n=count(head);
    return solve(head,n);

}