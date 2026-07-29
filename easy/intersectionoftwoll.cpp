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
    int findlength(ListNode *node){
        int count=0;
        while(node){
            count+=1;
            node=node->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        //find length of first
        //find length of second
        //if len1 > len2, get len1 starting corresponding to len2
        //if len2 > len1, get len2 starting corresponding to len1
        int len1 = findlength(headA);
        int len2 = findlength(headB);
        if(len2>len1){
            int diff = len2-len1;
            while(diff--){
                headB = headB->next;
            }
        }
        else{
            int diff = len1-len2;
            while(diff--){
                headA = headA->next;
            }
        }
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};