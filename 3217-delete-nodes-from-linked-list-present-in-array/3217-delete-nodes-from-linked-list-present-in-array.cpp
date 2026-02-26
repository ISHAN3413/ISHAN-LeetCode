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
         unordered_set<int> m(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0 , head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr!=nullptr){
            if(m.count(curr->val)){
                prev->next = curr->next;
            }
            else{
               prev = prev->next; 
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};