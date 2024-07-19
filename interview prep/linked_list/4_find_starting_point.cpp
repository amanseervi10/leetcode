/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* sp=head;
        ListNode* fp=head;
        int flag=0;
        if(head==NULL) return NULL;
        while(1){
            if(fp->next==NULL || fp->next->next==NULL){
                return NULL;
            }
            if(flag==1 && fp==sp){
                break;
            }
            sp=sp->next;
            fp=fp->next->next;
            flag=1;
        }  
        ListNode* t=head;
        while(t!=sp){
            sp=sp->next;
            t=t->next;
        }
        return t;
    }
};