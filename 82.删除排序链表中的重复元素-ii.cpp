/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummyHead(-1, head);
        ListNode* curr = &dummyHead;

        while (curr->next && curr->next->next) {
            ListNode* left = curr->next;
            ListNode* right = curr->next->next;

            if (left->val != right->val) {
                curr = left;
            } else {
                // 在此处不要去设置 curr 的指向,只设置 curr->next 的指向
                // 因为可能会有 3 3 4 4 这种连续的重复, 如果设置了 curr
                // 指向 3 或者 4, 后续就不好操作了
                while (right && right->val == left->val) {
                    right = right->next;
                    curr->next = right;
                }
            }
        }

        return dummyHead.next;
    }
};
// @lc code=end

