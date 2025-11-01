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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mpp;
        for(auto i : nums){
            mpp[i] = 1;
        }
        ListNode* temp = head;
        while(temp != NULL){
            if(mpp[temp->val] == 1) temp->val = 0;
            temp = temp->next;
        }
        ListNode* dum = new ListNode(-1, NULL);
        temp = head;
        ListNode* p1 = dum;
        while(temp != NULL){
            if(temp->val != 0){
                p1->next = temp;
                p1 = p1->next;
            }
            temp = temp->next;
        }
        p1->next = NULL;
        return dum->next;
    }
};