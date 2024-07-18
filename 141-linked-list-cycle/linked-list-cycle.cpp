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
    bool hasCycle(ListNode *head) {
        if(!head) return 0;
        ListNode* slow = head;
        ListNode* fast = head;

        do{
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }while(fast!=NULL && slow!=fast);

        if(!fast)return 0;
        return 1;
    }
};