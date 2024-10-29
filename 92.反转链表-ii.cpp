/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 初始 : 1->2->3->4->5, left = 2, right = 4
        ListNode dummyHead(0, head);

        // 找到 left 的上一个节点 : before_left
        // 假设 left = 1, 即可快速判断出 i < left - 1
        ListNode* before_left = &dummyHead;
        for (int i = 0; i < left - 1; i++) {
            before_left = before_left->next;
        }

        // 反转 left 到 right 这一段
        // 反转结束后 : prev在right, curr在right的下一个节点
        // 假设 right = left, 则可判断出 i < right - left + 1
        // 或者换种思考方式:需要反转 right - left + 1 个节点
        // 反转结束 : 1->2  4->3->2  5     
        ListNode* prev = nullptr;
        ListNode* curr = before_left->next;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // 反转结束后 : prev在right, curr在right的下一个节点
        // 并且此时的 before_next->next 仍然是 left
        // 这两行的顺序也不能反!!!
        // 第一行结束: 1->2->5   4->3->2
        // 第二行结束: 1->4->3->2->5
        before_left->next->next = curr;
        before_left->next = prev;

        return  dummyHead.next;
    }
};
// @lc code=end

