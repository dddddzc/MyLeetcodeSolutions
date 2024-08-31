/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void getNext(vector<int>& next, string& needle)
    {
        int n = needle.size();
        int i = 0;
        for(int j = 1; j < n; j++)
        {
            if(needle[i] == needle[j])
            {
                i++;
                next[j] = i;
            }
            else
            {
                if(i > 0)
                {
                    i = next[i - 1];
                    j--;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        if(needle == "")
        {
            return 0;
        }

        vector<int> next(needle.size(), 0);
        getNext(next, needle);

        int i = 0, j = 0;
        while(i < haystack.size())
        {
            if(haystack[i] == needle[j]) //匹配一个字符，ij都递增
            {
                i++;
                j++;
            }
            else if(j == 0) //从needle的一开始就没匹配上,继续往haystack的后边找
            {
                i++;
            }
            else    // 配了一部分,然后失配了,用Next数组找j该跳转的地方
            {
                j = next[j - 1];
            }

            if(j == needle.size())
            {
                return i - j;
            }
        }
        
        // int j = 0;
        // for(int i = 0; i < haystack.size();)
        // {
        //     if(haystack[i] == needle[j])
        //     {
        //         i++;
        //         j++;
        //     }
        //     else if(j == 0)
        //     {
        //         i++;
        //     }
        //     else
        //     {
        //         j = next[j - 1];
        //     }

        //     if(j == needle.size())
        //     {
        //         return i - j;
        //     }
        // }

        // int j = 0;
        // for(int i = 0; i < haystack.size(); i++)
        // {
        //     while(j > 0 && haystack[i] != needle[j])
        //     {
        //         j = next[j - 1];
        //     }

        //     if(haystack[i] == needle[j])
        //     {
        //         j++;
        //     }

        //     if(j == needle.size())
        //     {
        //         return i - j + 1;
        //     }
        // }
        
        return -1;
    }
};
// @lc code=end

