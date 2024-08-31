/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) 
        {
            return false;
        }

        vector<int> strMap(26, 0); 
        for(int i = 0; i < magazine.size(); ++i)
        {
            strMap[magazine[i] - 'a']++;
        }
        for(int i = 0; i < ransomNote.size(); ++i)
        {
            strMap[ransomNote[i] - 'a']--;
            if(strMap[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

