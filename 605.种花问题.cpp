/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        if (len == 1 && flowerbed[0] == 0)
        {
            return n <= 1;
        }

        int count = 0;
        if(flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            count++;
        }

        if(flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0)
        {
            flowerbed[len - 1] = 1;
            count++;
        }   

        for(int i = 1; i < len - 1; i++)
        {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }

        return count >= n;
    }
};
// @lc code=end

