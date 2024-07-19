void removeLoop(Node *head)
{
    Node* sp=head;
    Node* fp=head;
    int flag=0;
    while(1){
        if(fp->next==NULL && fp->next->next==NULL) break;
        sp=sp->next;
        fp=fp->next->next;
        if(fp==sp){
            flag=1; break;
        }
    }
    if(flag){
        Node* t=head;
        while(t!=sp){
            t=t->next;
            sp=sp->next;
        }
        while(sp->next!=t){
            sp=sp->next;
        }
        sp->next=NULL
    }
}