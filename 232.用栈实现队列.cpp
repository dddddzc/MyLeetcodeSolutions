/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> sIn;
    stack<int> sOut;

    MyQueue() {

    }
    
    void push(int x) {
        sIn.push(x);
    }
    
    int pop() {
        if(sOut.empty())
        {
            while(!sIn.empty())
            {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }

        int sOutTop = sOut.top();
        sOut.pop();
        return sOutTop;
    }
    
    int peek() {
        int res = this->pop();
        sOut.push(res);
        return res;
    }
    
    bool empty() {
        return sIn.empty() && sOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

