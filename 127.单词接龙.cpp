/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int n = 0;
    int minLen = 0;
    queue<string> strQueue;

    bool only1diff(string& a, string& b)
    {
        int diff = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) diff++;
        }
        return diff == 1;
    }

    void BFS(string& endWord, vector<string>& wordList, vector<bool>& visited, int depth)
    {
        // 一定要在queue遍历前记录下size,因为每轮操作完会变
        int currQsize = strQueue.size();
        for(int i = 0; i < currQsize; i++)
        {
            string tmp = strQueue.front();
            if(tmp == endWord)
            {
                minLen = depth; 
                return;
            }
            strQueue.pop();
            for(int j = 0; j < n; j++)
            {
                if(!visited[j] && only1diff(wordList[j], tmp)) 
                {
                    visited[j] = true;
                    strQueue.push(wordList[j]);
                }
            }
        }

        if(strQueue.empty()) return; // 如果路径断了,queue将为空,返回
        BFS(endWord, wordList, visited, depth + 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();
        vector<bool> visited(n, false);

        int i = 0;
        for(i; i < n; i++)
        {
            if(wordList[i] == endWord) break;
        }
        if(i == n) return 0; // 不在wordList中

        strQueue.push(beginWord);
        BFS(endWord, wordList, visited, 1);

        return minLen;
    }
};
// @lc code=end

