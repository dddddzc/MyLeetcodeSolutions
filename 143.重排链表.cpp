/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode* getMid(ListNode*& head) {
        // 找到中间节点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode*& head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void interlace(ListNode*& left, ListNode*& right) {
        while (right->next) {
            ListNode* l_next = left->next;
            ListNode* r_next = right->next;
            left->next = right;
            right->next = l_next;
            left = l_next;
            right = r_next;
        }
    }

    void reorderList(ListNode* head) {
        // if(!head || !head->next) {
        //     return;
        // }
        ListNode* mid = getMid(head);
        ListNode* reverse_mid = reverseList(mid);
        interlace(head, reverse_mid);
    }
};
// @lc code=end

