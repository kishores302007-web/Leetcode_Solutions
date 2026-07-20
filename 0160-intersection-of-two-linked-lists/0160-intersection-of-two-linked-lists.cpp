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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *c1 = headA, *c2 = headB;
        if(c1 == NULL || c2 == NULL){
            return NULL;
        }
        while(c1 != c2){
            if(c1 == NULL){
                c1 = headB;
            }
            else{
                c1 = c1 -> next;
            }
            if(c2 == NULL){
                c2 = headA;
            }
            else{
                c2 = c2 -> next;
            }
        } 
        return c2;
        
    }
};