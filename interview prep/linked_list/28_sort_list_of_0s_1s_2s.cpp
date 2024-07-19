//One basic approach can be to count the number of 0s,1s, and 2s
//And then simply fit it

//Another would be to have the approach used in the seggregate even and odd in linked list question
// Q. No : 33

//Just make three new dummy nodes each for 0,1,and 2. You can add nodes with 0s behind 0 dummynode and so on

Node *segregate(Node *head)
{
    int count0=0,count1=0,count2=0;

    Node* curr=head;
    while(curr!=NULL){
        if(curr->data==0) count0++;
        if(curr->data==1) count1++;
        if(curr->data==2) count2++;
        curr=curr->next;
    }

    curr=head;

    int count=0;
    while(curr!=NULL){
        if(count<count0){
            curr->data=0;
        }
        else if(count<count0+count1){
            curr->data=1;
        }
        else curr->data=2;
        count++;
        curr=curr->next;
    }

    return head;
}