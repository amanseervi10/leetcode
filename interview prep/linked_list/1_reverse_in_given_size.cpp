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

    void reverse(ListNode* r1, ListNode* r2,ListNode* right){
        if(r2==right){
            r2->next=r1;
            return;
        }
        reverse(r1->next,r2->next,right);
        r2->next=r1;
    }

    ListNode* reverseBetween(ListNode* head, int start, int end) {
        if(start==end) return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* right=dummy; ListNode* left=dummy;
        int k=end-start+1;
        while(k--) right=right->next;
        start--;
        while(start--){
            right=right->next;
            left=left->next;
        }
        ListNode* after=right->next;
        ListNode* before=left;
        reverse(left->next,left->next->next,right);
        left->next->next=after;
        before->next=right;
        return dummy->next;
    }
};