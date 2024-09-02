/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        unordered_map<int, int> umap;
        vector<int> res(n1, -1);
        for(int i = 0; i < n1; i++)
        {
            umap[nums1[i]] = i; // 建立 nums[i] 到 i 的映射
        }

        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && nums2[i] >= st.top())
            {
                st.pop(); // 抛弃比当前元素小的栈顶元素
            }
            // 加上非空是为了防止第一个元素,以及st为空时调用st.top()出错
            if(!st.empty() && umap.find(nums2[i]) != umap.end()) res[umap[nums2[i]]] = st.top();
            // 先算下标,后push,否则st.top()已经被更改
            st.push(nums2[i]);
        }

        return res;
    }
};
// @lc code=end

