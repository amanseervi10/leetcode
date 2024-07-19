//we can do this using normal inorder traversal and first count the number of nodes
//next time we can simply keep count and save the n/2th node or n/2th and n/2th +1 node

//here i am using morris traversal, it will take O(1) extra space

int countNodes(Node* root){
    int count=0;
    
    Node* curr=root,*prev;

    while(curr!=NULL){
        if(curr->left==NULL){
            count++;
            curr=curr->right;
        }
        else{
            prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                count++;
                curr=curr->right;
            }
        }
    }

    return count;
}

pair<int,int> solve(Node* root,int k){
    int count=0;
    int a,b; // a is nth, bis n/2 +1 th

    Node* curr=root,*prev;

    while(curr!=NULL){
        if(curr->left==NULL){
            count++;
            if(count==k/2) a=curr->data;
            else if(count==(k/2)+1) b=curr->data;
            curr=curr->right;
        }
        else{
            prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                count++;
                if(count==k/2) a=curr->data;
                else if(count==(k/2)+1) b=curr->data;
                curr=curr->right;
            }
        }
    }
    return {a,b};
}

float findMedian(struct Node *root)
{
    int k=countNodes(root);
    auto temp=solve(root,k);
    

    if(k%2){
        return temp.second;
    }
    else return (temp.first+temp.second)*1.0/2*1.0;
}