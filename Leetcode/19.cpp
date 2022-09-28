// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// 思路：快慢指针
// Tips：加头节点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode _head;
        _head.next = head;
        ListNode* slow = &_head;
        ListNode* quick = &_head;
        
        for(int i = 0; i < n; i++)
            quick = quick -> next;

        while(quick->next != NULL)
        {
            slow  = slow -> next;
            quick = quick -> next;
        }
        struct ListNode* del = slow -> next;
        slow -> next = slow -> next -> next;
        delete(del);
        
        return _head.next;
    }
};