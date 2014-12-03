class MinStack {
private:
    stack<int> minval;
    stack<int> val;
public:
    void push(int x) {
        val.push(x);
        if(minval.empty() || minval.top()>=x) minval.push(x);
    }

    void pop() {
        if(minval.top()==val.top()) minval.pop();
        val.pop();
    }

    int top() {
        return val.top();
    }

    int getMin() {
        return minval.top();
    }
};
