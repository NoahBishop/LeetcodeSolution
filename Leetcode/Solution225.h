#pragma once
#include <queue>
using namespace std;
class MyStack {
public:
    MyStack() {
        majar = 0;
    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int len = q.size();

        for (int i = 0; i < len - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        int res = q.front();
        q.pop();
        return res;
    }

    int top() {
        int len = q.size();

        for (int i = 0; i < len - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        
        int res = q.front();
        q.push(q.front());
        q.pop();
        return res;
    }

    bool empty() {
        return q.empty();
    }

    queue<int> q;
    int majar;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */