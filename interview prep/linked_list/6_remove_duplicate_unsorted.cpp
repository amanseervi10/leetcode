/*

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        set<int> store; //to store the values which have been encountered

        store.insert(head->data);
        Node* prev=head;  //to store the prev element
        Node* curr=head->next; //the pointer which will move
        
        while(curr!=NULL){
            if(!store.count(curr->data)){
                store.insert(curr->data);
                curr=curr->next;
                prev=prev->next;
            }
            else{
                prev->next=curr->next;
                curr=prev->next;
            }
        }

        return head;
    }
};