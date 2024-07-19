/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
    if(!head) return true;
    Node *fast=head;
    Node *slow=head;

    while(1){
        if(fast->next==NULL  || fast->next->next==NULL) return false;
        else{
            fast=fast->next->next;
            slow=slow->next;
        }
        if(slow==fast) return true;
    } 
}