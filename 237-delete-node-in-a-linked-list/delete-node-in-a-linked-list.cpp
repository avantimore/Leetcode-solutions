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
        int num = node->next->val;
        ListNode* del = node->next;
        node->val = num;
        node->next = node->next->next;
        delete(del);
    }
};