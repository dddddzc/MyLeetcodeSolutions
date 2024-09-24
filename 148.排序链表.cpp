/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void swapNode(ListNode* prev, ListNode* curr)
    {
        ListNode* tail = curr->next->next;
        prev->next = curr->next;
        prev->next->next = curr;
        prev->next->next->next = tail;
    }

    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        // 添加 dummyHead
        ListNode dummyHead(-10001);
        dummyHead.next = head;

        while(curr->next)
        {
            if(curr->next->val < curr->val)
            {
                swapNode(curr, curr->next);
            }
            curr = curr->next;
        }
    }
};
// @lc code=end

