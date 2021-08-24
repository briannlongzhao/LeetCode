/* 21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l1n = nullptr;
        ListNode* l2n = nullptr;
        ListNode* ls = nullptr;
        ListNode* ltmp = nullptr;
        if (l1 && l2) {
            l1n = l1->next;
            l2n = l2->next;
            if (l1->val < l2->val) {
                ls = l1;
                l1 = l1->next;
                if (l1n) {
                    l1n = l1n->next;
                }
                ltmp = ls;
            }
            else {
                ls = l2;
                l2 = l2->next;
                if (l2n) {
                    l2n = l2n->next;
                }
                ltmp = ls;
            }
        }
        else if (l1) {
            return l1;
        }
        else {
            return l2;
        }
        while (true) {
            if (!l1 && !l2) {
                return ls;
            }
            else if (!l1) {
                ltmp->next = l2;
                return ls;
            }
            else if (!l2) {
                ltmp->next = l1;
                return ls;
            }
            else {
                if (l1->val < l2->val) {
                    ltmp->next = l1;
                    l1 = l1n;
                    if (l1n) {
                        l1n = l1n->next;
                    }
                }
                else {
                    ltmp->next = l2;
                    l2 = l2n;
                    if (l2n) {
                        l2n = l2n->next;
                    }
                }
                ltmp = ltmp->next;
            }
        }
    }
};