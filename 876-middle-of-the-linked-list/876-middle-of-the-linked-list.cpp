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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        
        //slow and fast pointers : 
        ListNode* slow = head;
        ListNode* fast = head; 
        
        //slow will move by 1, and fast will move by 2.
        //condition will be using fast pointer, as it's ultimately going to exceed the linked list
        
        //
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
};