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

    bool isPalindrome(ListNode* head) {
        ListNode* endOfFirstHalf = findMiddle(head);
        ListNode* right = reverseSegment(endOfFirstHalf);
        ListNode* left = head;
        
        while(right != nullptr) {
            if(left -> val != right -> val) return false;
            left = left -> next;
            right = right -> next;
        }
        
        return true;
    }
    
private: 
    //head, will point to the reverse of the array    
    ListNode* reverseSegment(ListNode* head) {
        ListNode* dummy = nullptr;
        ListNode* next = nullptr;
        
        while(head != nullptr) {
            next = head -> next;
            head -> next = dummy;
            dummy = head;
            head = next;
        }
        
        return dummy;
        
    }
    
    // even elements -> returns pointer to the first element of second half
    // odd elements -> returns pointer to the middle element
    
    // in all cases we need the other half, so we'll tweak a bit.
    ListNode* findMiddle(ListNode* head) {
        
        ListNode* slow = head; //will move 1 step
        ListNode* fast = head; //will move 2 step
        
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        //for even it's already giving a pointer to the end of first half
        //but for odd, it's the middle element, so incrementing it to the next node, 
        // which will be next to the middle element.
        
        if(fast != nullptr) slow = slow -> next;
        return slow;
        
    }
};