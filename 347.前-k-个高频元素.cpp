/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        // calculate the frequency
        for(auto num : nums)
        {
            um[num]++;
        }

        class myCompare{
        public:
            bool operator()(const pair<int, int>& num1, const pair<int, int>& num2) const
            {
                return num1.second > num2.second; // 小顶堆
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> pq;
        for(auto m : um)
        {
            if(pq.size() == k)
            {
                if(pq.top().second < m.second)
                {
                    pq.pop();
                    pq.emplace(m);
                }
            }
            else
            {
                pq.emplace(m);
            }
        }

        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
// @lc code=end

