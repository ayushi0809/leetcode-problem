class MyCircularDeque {
public:
    list<int>l;
    int size;
    int count =0;
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(count<size){
            l.push_front(value);
            count++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(count<size){
            l.push_back(value);
            count++;
            return true;
        }
        return false;
        
    }
    
    bool deleteFront() {
        if(count>0){
            l.pop_front();
            count--;
            return true;
        }
        return false;
        
    }
    
    bool deleteLast() {
        if(count>0){
            l.pop_back();
            count--;
            return true;
        }
        return false;
        
    }
    
    int getFront() {
        if(count>0){
        return *l.begin();
        }
        return -1;
        
    }
    
    int getRear() {
        if(count>0){
        return *l.rbegin();
        }
        return -1;
        
    }
    
    bool isEmpty() {
        return count==0;
        
    }
    
    bool isFull() {
        return count==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */