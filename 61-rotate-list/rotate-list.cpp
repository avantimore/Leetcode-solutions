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
    int findLength(ListNode* head){
        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        int len = findLength(head);
        k = k % len; // Normalize k
        if (k == 0) {
            return head;
        }

        int toGo = len - k;
        ListNode* temp = head;
        
        // Move toGo nodes ahead
        while (--toGo) {
            temp = temp->next;
        }
        
        // Store the new head and break the list
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        // Traverse to the end of the new list
        temp = newHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        // Attach the old head to the end of the list
        temp->next = head;

        return newHead;
    }
};