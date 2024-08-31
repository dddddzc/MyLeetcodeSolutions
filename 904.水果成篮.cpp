/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int maxFruit = 0;
        map<int, int> collected;
        for(int j = 0; j < fruits.size(); ++j)
        {
            collected[fruits[j]]++;
            // if kind >= 3
            while(collected.size() > 2)
            {
                // the kind of i will be removed, then the kind num will be 1.
                if(collected[fruits[i]] == 1)
                {
                    collected.erase(fruits[i]);
                }
                else
                {
                    collected[fruits[i]]--;
                }
                ++i;
            }
            // now the kind of fruits are <= 2
            maxFruit = max(maxFruit, j - i + 1);
        }
        return maxFruit;
    }
};
// @lc code=end

