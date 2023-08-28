class MyStack {
public:
    queue<int>q;
    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while(q.size()-1 != 0){
            // cout<<q.front()<<endl;
            q1.push(q.front());
            q.pop();
        }
        int x = q.front();
         q.pop();
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        return x;
        
    }
    
    int top() {
        while(q.size()-1 != 0){
            q1.push(q.front());
            q.pop();
        }
        int x = q.front();
        // q.pop();
        q1.push(q.front());
        q.pop();
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        return x;
        
    }
    
    bool empty() {
        return q1.empty() && q.empty();
        
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