/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    //this function return {newHead,newTail} after reversing a small group of k Nodes
    pair<ListNode*,ListNode*> reverse(ListNode* head, int k){
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* save=curr->next;
        k=k-1;
        while(k--){
            curr->next=prev;
            prev=curr;
            curr=save;
            if(save!=NULL) save=save->next;
        }
        return {prev,head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head->next==NULL || k==1) return head;
        //first find length
        ListNode* move=head;
        int length=0;
        while(move!=NULL){
            length++; move=move->next;
        }
        
        ListNode* newOverallHead;
        //first always save the next (k+1)th node;
        int count=k;
        ListNode* save=head;
        while(count--) save=save->next;
        
        auto temp=reverse(head,k); length-=k;
        temp.second->next=save;
        newOverallHead=temp.first;

        ListNode* prevTail=temp.second;
        while(length>=k){
            count=k;
            ListNode* curr=save;
            while(count--) save=save->next;
            temp=reverse(curr,k);
            prevTail->next=temp.first;
            temp.second->next=save;
            prevTail=temp.second;
            length-=k;
        }

        return newOverallHead;
    }
};