class comparator{
    public:
    bool operator()(Node* l1,Node* l2){
        return (l1->data>l2->data);
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node*,comparator> pq;
        for(int i=0; i<K; i++) pq.push(arr[i]);  //inserting into heap  

        Node* head=new Node(0);
        Node* curr=head;

        while(!pq.empty()){
            curr->next=new Node(pq.top()->data);
            Node* temp=pq.top()->next;
            pq.pop();
            if(temp!=NULL) pq.push(temp);
            curr=curr->next;
        }        

        return head->next;
    }
};