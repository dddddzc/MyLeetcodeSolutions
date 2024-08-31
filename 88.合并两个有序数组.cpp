/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0)
        {
            nums1 = nums2;
        }

        else
        {
            for(int i = m - 1, j = n - 1; i > -1 && j > -1;)
            {
                // 依次比较末尾的数谁大，然后往num1向前塞
                if(nums2[j] >= nums1[i])
                {
                    nums1[i + j + 1] = nums2[j];
                    --j;
                }
                else
                {
                    nums1[i + j + 1] = nums1[i];
                    --i;
                }

                // 如果nums2已经用完了,而nums1还没遍历完，则正常结束
                // 下面要处理,num1已经用完了,但nums2还没用完:
                // 将nums2剩下的数挪到num1的前边。
                if(i == -1 && j >= 0)
                {
                    for(j; j >= 0; --j)
                    {
                        nums1[j] = nums2[j];
                    }
                    j--;
                }
            }
        }
    }
};
// @lc code=end

