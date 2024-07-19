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
    ListNode* middleNode(ListNode* head) {
        ListNode* sp=head;
        ListNode* fp=head;
        while(1){
            if(fp->next==NULL){
                break;
            }
            if(fp->next->next==NULL){
                sp=sp->next;
                break;
            }
            fp=fp->next->next;
            sp=sp->next;
        }
        return sp;
    }
};