/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> last_idx(26, 0);
        // 第一次遍历得到last_idx
        for(int i = 0; i < n; i++)
        {
            last_idx[s[i] - 'a'] = i;
        }

        vector<int> split;
        int start = 0, end = 0;// start end用于标记一个区间
        // 第二次遍历,每次遇到新字母，则更新end为更大的值
        for(int i = 0; i < n; i++)
        {
            end = max(end, last_idx[s[i] - 'a']);
            // 如果i == end,则说明该区间遍历完毕
            if(i == end)
            {
                split.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return split;
    }
};

// @lc code=end

