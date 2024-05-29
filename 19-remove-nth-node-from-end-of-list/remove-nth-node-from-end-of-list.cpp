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
    ListNode* recursivecall(ListNode* head, int n, int& count, int& len) {
        len++;
        if(head==NULL || head->next==NULL) {
            return head;
        }
        recursivecall(head->next, n, count, len);
        count++;
        // when 1st element from last needs to be deleted
        if(count==1 && n==1) {
            head->next=NULL;
        }
        if(count==n && n!=1) {
            head->next=head->next->next;
            
        }
        // when 1st element needs to be deleted
        if(count==len-1 && n==len) {
            return head->next;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0, len=0;
        if(head->next==NULL && n==1) {
            return NULL;
        }
        return recursivecall(head, n, count, len);
    }
};