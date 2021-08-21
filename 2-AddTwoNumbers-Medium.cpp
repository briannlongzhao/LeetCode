/* 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

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
        ListNode *retval = new ListNode();
        ListNode *curr = retval;
        int carry = 0;
        if (l1->val + l2->val >= 10) {
            carry = 1;
        }
        retval->val = (l1->val + l2->val) % 10;
        while ((l1->next != nullptr || l2->next != nullptr) || carry != 0) {
            int l1val = 0, l2val = 0, currval = 0;
            if (l1->next != nullptr) {
                l1 = l1->next;
                l1val = l1->val;
            }
            if (l2->next != nullptr) {
                l2 = l2->next;
                l2val = l2->val;
            }
            curr->next = new ListNode();
            curr = curr->next;
            currval = l1val + l2val + carry;
            if (currval >= 10) {
                carry = 1;
            }
            else {
                carry = 0;
            }
            curr->val = currval % 10;
        }
        return retval;
    }
};