struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k, int v){
        key = k;
        value = v;
        prev = next = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>m;
    int s;
    int count= 0;
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    LRUCache(int capacity) {
        s=capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
         
        Node* temp = m[key];
        Node* p = temp->prev;
        Node* q = temp->next;
        p->next = q;
        q->prev = p;
        Node* r = new Node(temp->key, temp->value);
        Node* headnext = head->next;
        head->next = r;
        r->prev = head;
        r->next = headnext;
        headnext->prev = r;
        int val = temp->value;
        m.erase(key);
        m[key] = r;
        delete temp;
        return val;
        
    }
    
    void put(int key, int value) {
        Node* newnode = new Node(key, value);
        Node* headnext = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = headnext;
        headnext->prev = newnode;
        if(m.find(key) != m.end()){
            Node* temp = m[key];
            Node* p = temp->prev;
            Node* q = temp->next;
            p->next = q;
            q->prev = p;
            m.erase(key);
            m[key] = newnode;
            delete temp;
        }
        else if(count<s){
            
            m[key] = newnode;  
            count++;
        
        }
        else{
            Node* temp = tail->prev;
            Node* p = temp->prev;
            p->next = tail;
            tail->prev = p;
            m.erase(temp->key);
            m[key] = newnode;
            delete temp;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */