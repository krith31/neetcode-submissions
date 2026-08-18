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
    ListNode* reverse(ListNode* temp){
        ListNode* prev=NULL;
        ListNode* nextnode;
        while(temp!=NULL){
            nextnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextnode;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverse(head);
        if (n==1) {
            head=head->next;
            return reverse(head);
        }
        ListNode* temp=head;

        for (int count=1; count<n-1;count++) {
            temp=temp->next;
        }

        temp->next = temp->next->next;
        head=reverse(head);
        return head;
    }
};
