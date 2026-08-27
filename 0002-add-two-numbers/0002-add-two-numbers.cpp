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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, rem = 0;
        ListNode* head = nullptr; ListNode* tail = nullptr;
        while(carry || l1 || l2){
            if(l1){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2){
                carry += l2->val;
                l2 = l2->next;
            }
            if(carry >= 0){
                rem = carry % 10;
                carry /= 10;
                ListNode* newnode = new ListNode(rem);
                if(head == nullptr){
                    head = newnode;
                    tail = newnode;
                }
                else{
                    tail->next =  newnode;
                    tail = newnode;
                }
            }
        }
        return head;
    }
};