/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> myHash(26, 0);
        for(auto iter = s.begin(); iter != s.end(); ++iter)
        {
            myHash[*iter - 'a']++;
        }
        for(auto iter = t.begin(); iter != t.end(); ++iter)
        {
            myHash[*iter - 'a']--;
        }
        for(auto iter = myHash.begin(); iter != myHash.end(); ++iter)
        {
            if(*iter != 0)
            {
                return false;
            }
        }        
        return true;
    }
};
// @lc code=end

