/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> adjList(numCourses);    // 数组+链表:邻接表
        vector<int> indegree(numCourses, 0);      // 每个节点的入度

        // 构建链式邻接表,计算每个点的入度
        for(auto& pre : prerequisites)
        {
            adjList[pre[0]].push_back(pre[1]); // 有向边 : pre[0]指向pre[1],pre[1]是前置课程
            indegree[pre[1]]++;                // 前置课程 pre[1] 的入度加一
        }

        // 找出入度为0的点,加入队列(可能不止一个)
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int course_count = 0;  // 可以上的课
        while(!q.empty())
        {
            int curr_course = q.front(); // 当前无需任何前置课程的课
            q.pop();
            course_count++;
            for(auto& prev_course : adjList[curr_course]) // 取出curr_course的所有前置课程prev_course
            {
                indegree[prev_course]--;                  // 将prev_course的入度都减1
                if(indegree[prev_course] == 0)
                {
                    q.push(prev_course);
                }
            }
        }

        return course_count == numCourses;
    }
};
// @lc code=end

