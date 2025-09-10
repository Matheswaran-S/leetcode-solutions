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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0,sum;
        if(!l1 && !l2) return NULL;
        ListNode* dum = new ListNode(-1,NULL);
        ListNode* temp = dum;
        ListNode* l = l1, *r = l2;
        while(l && r){
            sum = (carry + l->val + r->val);
            l->val = sum % 10;
            carry = sum/10;
            temp->next = l;
            temp = temp->next;
            l = l->next;
            r = r->next;
        }
        while(l){
            sum  = (carry + l->val);
            l->val = sum % 10;
            carry = sum/10;
            temp->next = l;
            temp = temp->next;
            l = l->next;
        }
        while(r){
            sum = (carry + r->val);
            r->val = sum % 10;
            carry = sum/10;
            temp->next = r;
            temp = temp->next;
            r = r->next;
        }
        //cout<<carry;
        if(carry >= 1){
            ListNode* t = new ListNode(carry,NULL);
            temp->next = t;
            cout<<"hjsgdkfhgsk";
        }
        return dum->next;
    }
};