/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stack_;
    stack<int> min_stack;
    MinStack() {
    }
    
    void push(int x) {
        if (min_stack.empty() || x <= min_stack.top()){
            min_stack.push(x);
        }
        stack_.push(x);
    }
    
    void pop() {
        int top_ = stack_.top();
        if (top_ <= min_stack.top()){
            min_stack.pop();
        }
        stack_.pop();
    }
    
    int top() {
        if (!stack_.empty()) return stack_.top();
        else return -1;
    }
    
    int getMin() {
        if (!min_stack.empty()) return min_stack.top();
        else return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

