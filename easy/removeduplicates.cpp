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
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* parent= nullptr;
        int prev= -101;
        ListNode* mover = head;
        while(mover){
            if(mover->val == prev){
                parent->next = mover->next;
                ListNode* temp = mover;
                mover=mover->next;
                delete temp;
            }
            else{
                parent = mover;
                prev = mover->val;
                mover=mover->next;
            }
        } 
        return head;
    }
};

//errors = not accounting for constraints of allowed values, ie, -1 se compare karna