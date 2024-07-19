class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next==NULL) return true;
        Node *curr=head;
        Node *fast=head;
        Node *slow=head;

        //Going to the middle or atleast sort of
        while(1){
            if(fast->next==NULL || fast->next->next==NULL) break;
            else{
                fast=fast->next->next;
                slow=slow->next;
            }
        }

        //Now we reverse the linked list    
        Node* move=slow->next; //the one where we reverse
        Node* prev=slow;        //the previous ofcourse
        Node* save=move->next; //the next of the the move

        while(1){
            move->next=prev;
            if(save==NULL) break;
            prev=move;
            move=save;
            save=save->next;
        }

        //Now move is essentially the last element and half of the linked list is reversed
        //Just traverse and you can find if palindrome

        while(1){
            if(head->data!=move->data) return false;
            if(head->next==move->next) break;
            else if(head->next==move) break;
            else{
                head=head->next;
                move=move->next;
            }
        }
        return true;
    }
};