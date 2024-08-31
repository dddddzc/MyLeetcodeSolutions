/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);

        int flag = strNum.size();
        for(int i = strNum.size() - 1; i > 0; i--)
        {
            if(strNum[i - 1] > strNum[i])
            {
                flag = i;
                strNum[i - 1]--;
            }
        }

        // 从flag位开始,后边的都设为9
        for(int i = flag; i < strNum.size(); i++)
        {
            strNum[i] = '9';
        }

        return stoi(strNum);
    }
};
// @lc code=end

