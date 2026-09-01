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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-5001);
        ListNode *p = head;
        while(p){
            ListNode *r = p->next;
            ListNode *q = dummy;

            while( q->next && q->next->val < p->val){
                q = q->next;
            }
            p->next = q->next;
            q->next = p;

            p = r;
        }

        return dummy->next;
    }
};