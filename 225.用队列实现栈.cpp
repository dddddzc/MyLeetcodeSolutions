/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        while(n > 1)
        {
            q.push(q.front());
            q.pop();
            n--;
        }
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        int res = this->pop();
        q.push(res);
        return res;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

