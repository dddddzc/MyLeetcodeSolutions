/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 计算总共有多少个节点
        ListNode* iter = head;
        int N = 0;
        while (iter) {
            iter = iter->next;
            N++;
        }
        int groups = N / k;

        // p0和dummyHead最初指向同一个节点
        ListNode dummyHead(0, head);
        ListNode* p0 = &dummyHead;

        // 反转链表模板
        ListNode* prev = nullptr;
        ListNode* curr = p0->next;
        // i是组的序号
        for (int i = 1; i <= groups; i++) {
            // j是当前组中已经翻转的个数
            for (int j = 0; j < k; j++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // 翻转一次之后, prev是当前组的最后一个, curr是下一组的第一个
            // p0 在下一组反转前,要更改为当前组中的p0->next
            // 而 p0->next 在将头尾倒转时会被改变, 需要用临时变量 p0_next 存起来。
            ListNode* p0_next = p0->next;
            p0->next->next = curr;
            p0->next = prev;
            p0 = p0_next;
        }

        return dummyHead.next;

    }
};
// @lc code=end

