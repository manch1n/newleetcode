#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <list>
using namespace std;


class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> _q1;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> _q2;
        _q2.push(x);
        for(int i=0;i<_q1.size();++i)
        {
            _q2.push(_q1.front());
            _q1.pop();
        }
        std::swap(_q1,_q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t=_q1.front();
        _q1.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return _q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _q1.empty();
    }
};


int main(int argc,char** argv)
{
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.pop();
    s.pop();
    bool e=s.empty();
    getchar();
    return 0;
}
