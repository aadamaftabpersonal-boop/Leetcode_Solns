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
    bool hasCycle(ListNode *head){
        if(head==nullptr)return false;
        if(head->next == nullptr)return false;
        ListNode *m1 = head;
        ListNode *m2 = head->next;
        while(m1 && m2){
            if(m1==m2)return true;
            m1 = m1->next;
            if(m2->next)m2 = m2->next->next;
            else return false;
        }
        return false;
    }
};

//edge case if m1->next doesnt exist
