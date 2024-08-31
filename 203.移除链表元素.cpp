/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
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

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // virtual new head
        ListNode* virtualHead = new ListNode(0);
        virtualHead->next = head;
        ListNode* currentNode = virtualHead;
        while(currentNode->next != nullptr)
        {
            if(currentNode->next->val == val)
            {
                ListNode* toDelete = currentNode->next;
                currentNode->next = currentNode->next->next;
                delete(toDelete);
            }
            else
            {
                currentNode = currentNode->next;
            }
        }
        // set the head back to the original one
        head = virtualHead->next;
        delete(virtualHead);
        return head;
    }
};
// @lc code=end

