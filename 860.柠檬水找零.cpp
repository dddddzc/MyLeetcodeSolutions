/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // rest[0] : 5  
        // rest[1] : 10
        vector<int> rest(2,0);
        for(int i = 0; i < bills.size(); i++)
        {
            switch (bills[i])
            {
            case 5:
                rest[0] += 1;
                break;
            case 10:
                if(rest[0] < 1) return false;
                rest[0]--;
                rest[1]++;
                break;
            case 20:
                if(rest[1] > 0 && rest[0] > 0)
                {
                    rest[0]--;
                    rest[1]--;
                }
                else if(rest[0] >= 3)
                {
                    rest[0] -= 3;
                }
                else return false;
                break;
            }
        }
        return true;
    }
};
// @lc code=end

