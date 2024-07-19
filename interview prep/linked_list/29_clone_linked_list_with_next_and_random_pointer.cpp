//First is the map based method
//refer this for constant space method : https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/

Node *copyList(Node *head)
{

    unordered_map<Node*, Node*> mp;

    Node* dummy=new Node(-1);
    Node* curr=dummy;

    Node* temp=head;
    while(temp!=NULL){
        curr->next=new Node(temp->data);
        mp[temp]=curr->next;
        temp=temp->next;
        curr=curr->next;
    }

    curr=dummy->next;
    temp=head;

    while(curr!=NULL){
        if(temp->arb!=NULL){
            curr->arb=mp[temp->arb];
        }
        temp=temp->next;
        curr=curr->next;
    }

    return dummy->next;
}