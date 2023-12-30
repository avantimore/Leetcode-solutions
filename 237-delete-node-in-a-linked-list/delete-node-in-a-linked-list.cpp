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
    void deleteNode(ListNode* node) {
        ListNode* toremove=node->next;
        node->val = node->next->val; //copying the next node value
        node->next = node->next->next; // deleting the next node
        toremove->next=NULL;
        delete(toremove);
    }
};