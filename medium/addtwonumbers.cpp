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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode(0);
        ListNode* mover = dummy;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            int toadd = sum%10;
            carry = sum/10;
            mover->next = new ListNode(toadd);
            mover = mover->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            int toadd = sum%10;
            carry = sum/10;
            mover->next= new ListNode(toadd);
            mover=mover->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + carry;
            int toadd = sum%10;
            carry = sum/10;
            mover->next = new ListNode(toadd);
            mover = mover->next;
            l2 = l2->next;
        }
        if(carry){
            mover->next = new ListNode(1);
        }
        return dummy->next;
    }
};