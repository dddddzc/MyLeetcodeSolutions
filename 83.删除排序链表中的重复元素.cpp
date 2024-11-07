/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 只有0个或1个节点的时候
        if (!head || !(head->next)) {
            return head;
        }

        ListNode* curr = head;
        // 如果 curr->next 与 curr 相同, 删除 curr->next
        // 否则将 curr 更改为 curr->next.
        while (curr->next) {
            if (curr->next->val == curr->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
// @lc code=end

