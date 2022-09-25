class MyCircularQueue {
    struct ListNode{
        public:
        int data;
        ListNode* next;
        ListNode(int x){
            data = x;
            next = NULL;
        }
         ListNode() : data(0), next(nullptr) {}
    };
public:
    int K=0;
    int size =0;
    ListNode* node;
    ListNode* front;
    ListNode* rear;
    MyCircularQueue(int k) {
        K=k;
        size=k;
        node = new ListNode();
        node->next = node;
        front = node;
        rear= node;
    }
    
    bool enQueue(int value) {
        if(K>0){
            K--;
        ListNode* head = node->next;
        ListNode* newnode = new ListNode(value);
        node->next = newnode;
        newnode->next=head;
        node=node->next;
        rear = node;
            return true;
        }
        else{
            return false;
        }
        
    }
    
    bool deQueue() {
        if(K<size){
            ListNode* del = front->next;
            if(size-K==1){
                front->next = front;
                node=front;
            }
            else{
                front->next = del->next;
                delete del;
            }
            K++;
            return true;
        }
        
        return false;
        
    }
    
    int Front() {
        if(K<size){
            //cout<<front->next->data;
            return front->next->data;
        }
        return -1;
        
    }
    
    int Rear() {
        if(K<size){
            //cout<<rear->data;
            return rear->data;
        }
        return -1;
        
    }
    
    bool isEmpty() {
       
        if(K==size)
            return true;
        return false;
    }
    
    bool isFull() {
        
        if(K==0)
            return true;
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */