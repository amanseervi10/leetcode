/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    Node* curr=*head;
    while(curr->next->data!=key) curr=curr->next;
    curr->next=curr->next->next;
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{

    Node* head=*head_ref;
    Node* curr=head;
    Node* prev=curr;
    curr=curr->next;
    Node* save=curr->next;

    while(curr!=head){
        curr->next=prev;
        prev=curr;
        curr=save;
        save=save->next;
    }
    curr->next=prev;
    *head_ref=prev;

}