/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmpHeight(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmpHeight);

        for(auto& person : people)
        {
            // 使用insert时,例如[5,0]会把[7,0]挤到后一格去
            res.insert(res.begin() + person[1], person);
        }

        return res;
    }
};
// @lc code=end

