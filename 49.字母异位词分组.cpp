/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string countHash(string& strs)
    {
        vector<int> myHash(26, 0);
        for(auto i = strs.begin(); i != strs.end(); ++i)
        {
            myHash[*i - 'a']++;
        }

        string strHash;
        for(auto i = 0; i < 26; ++i)
        {
            if(myHash[i] != 0)
            {
                // avoid only bits 10
                // string s1 = "bdddddddddd";
                // string s2 = "bbbbbbbbbbc";
                strHash.push_back(i + 'a');
                strHash += to_string(myHash[i]);
            }
        }
        return strHash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> everyHash(n);
        unordered_map<string, vector<string>> groups;
        for(auto i = 0; i < n; ++i)
        {
            everyHash[i] = countHash(strs[i]);

            auto iter = groups.find(everyHash[i]);
            if(iter == groups.end())
            {
                groups.insert({everyHash[i], vector<string>(1, strs[i])});
            }
            else
            {
                iter->second.push_back(strs[i]);
            }
        }
        
        vector<vector<string>> ans;
        for (auto& group : groups) 
        {
            ans.push_back(group.second);
        }
        return ans;

    }
};
// @lc code=end

