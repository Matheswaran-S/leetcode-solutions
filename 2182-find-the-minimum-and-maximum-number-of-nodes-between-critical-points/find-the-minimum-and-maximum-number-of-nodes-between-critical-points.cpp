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
    int len(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || len(head) <= 3) return {-1,-1};
        vector<int> v;
        int index = 1;
        ListNode* prev = head;
        ListNode* current = head->next;
        ListNode* nest = head->next->next;
        while(nest != NULL){
            if(current->val < prev->val && current->val < nest->val || current->val > prev->val && current->val > nest->val){
                v.push_back(index);
            }
            prev=prev->next;
            current = current->next;
            nest = nest->next;
            index++;
        }
        int sizev = v.size();
        if(sizev <= 1) return {-1,-1};
        int mini = INT_MAX, pre = v[0];
        for(int i=1; i<sizev; i++){
            mini = min(mini, v[i]-pre);
            pre = v[i];
        }
        return {mini,v[sizev-1]-v[0]};
    }
};