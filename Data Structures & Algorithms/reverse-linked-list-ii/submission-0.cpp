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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count=0;
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* nextNode;
        if (left==right){
            return head;
        }
        while(1){
            count++;
            if(count==left){
                break;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
            
        }
        ListNode* prev_1=prev;
        ListNode* leftnode=temp;
        nextNode=temp->next;
        while(1){
            if(count==right){
                temp->next=NULL;
                break;
            }
            else{
                nextNode=nextNode->next;
                temp=temp->next;
            }
            count++;
        }
        reverse(leftnode);
        if (prev_1 != NULL)
            prev_1->next = temp;
        else
            head = temp;
        leftnode->next=nextNode;
        return head;

        
    }
};