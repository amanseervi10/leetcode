//Iterative

// Node* sortedMerge(Node* head1, Node* head2)  
// {  
//     Node* dummy=new Node(-1);
//     Node* curr=dummy;
    
//     while(head1!=NULL && head2!=NULL){
//         if(head1->data<=head2->data){
//             curr->next=head1;
//             head1=head1->next;
//             curr=curr->next;
//         }  
//         else{
//             curr->next=head2;
//             head2=head2->next;
//             curr=curr->next;
//         }
//     }
    
//     if(head1!=NULL){
//         curr->next=head1;
//     }
//     if(head2!=NULL){
//         curr->next=head2;
//     }
//     return dummy->next;
// }  


//Recursive
// solve(Node* a,Node* b){

//     if(a==NULL) return b;
//     if(b==NULL) return a;

//     Node* ans;
//     if(a->data>b->data){
//         ans=b;
//         b->next=solve(a,b->next);
//     }
//     else{
//         ans=a;
//         a->next=solve(a->next,b);
//     }

//     return ans;
// }