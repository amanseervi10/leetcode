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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* sp=head;
        ListNode* fp=head;
        while(1){
            if(fp->next==NULL || fp->next->next==NULL) return false;
            else{
                sp=sp->next;
                fp=fp->next->next;
            }
            if(sp==fp) return true;
        }
    }
};