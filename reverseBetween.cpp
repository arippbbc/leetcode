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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head->next==NULL || m==n) return head;
        ListNode *front=head, *p1, *p2, *p3;

        int i = 1;
        if(m==1){
            p1 = head; 
            p2 = p1->next;
            p3 = p2->next;
        }

        else{
            while(i<m){
                front = front->next;
                ++i;
            }

            p1 = front->next;
            p2 = p1->next;
            p3 = p2->next;
        }

        ListNode *newend = m==1?head:front->next;

        while(i<n){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            ++i;
        }

        if(m>1){
            front->next = p1;
            newend->next = p2;
            return head;
        }

        else{
            newend->next = p2;
            return p1;
        }
    }
};

