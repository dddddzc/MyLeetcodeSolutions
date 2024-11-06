/*
@lc app=leetcode.cn id=19 lang=cpp
 *
[19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // // 计算链表总长度 N
        // int N = 0;
        // ListNode* curr = head;
        // while (curr)
        // {
        //     curr = curr->next;
        //     N++;
        // }

        // // n >= N 时的特判
        // if(n > N) {
        //     return head;
        // }
        // if(n == N) {
        //     ListNode* head_next = head->next;
        //     delete head;
        //     return head_next;
        // }

        // // 其他普通情况下的删除
        // int del_prev = N - n - 1;
        // int i = 0;
        // curr = head;
        // while (i < del_prev)
        // {
        //     curr = curr->next;
        //     i++;
        // }
        // ListNode* del = curr->next;
        // ListNode* del_next = curr->next->next;
        // curr->next = del_next;
        // delete del;

        // return head;

        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        while (n)
        {
            fast = fast->next;
            n--;
        }

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return dummy.next;
    }
};
// @lc code=end

