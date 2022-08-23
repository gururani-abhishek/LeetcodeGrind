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
    // tc : O(n), space : O(n)
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return false;
        
        vector<int> arr;
        
        while(head != NULL) {
            arr.push_back(head -> val);
            head = head -> next;
        }
        
        return checkPali(arr);
    }
    
private: 
    bool checkPali(vector<int> &arr) {
        int left = 0, right = arr.size() -1;
        while(left < right) {
            if(arr[left] != arr[right]) return false;
            left++, right--;
        }
        
        return true;
    }
};