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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=nullptr){
            ListNode* nextnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextnode;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_l1 = l1;
        ListNode* new_l2 = l2;

        int carry = 0;
        ListNode* head = nullptr;

        while (new_l1 != nullptr || new_l2 != nullptr || carry != 0) {
            int sum = carry;

            if (new_l1 != nullptr) {
                sum += new_l1->val;
                new_l1 = new_l1->next;
            }

            if (new_l2 != nullptr) {
                sum += new_l2->val;
                new_l2 = new_l2->next;
            }

            carry = sum / 10;
            
            // Prepending the node builds the final list in the correct order directly
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }

        return reverse(head);

    }
};
