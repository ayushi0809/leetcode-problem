class MyHashSet {
public:
    list<int>*table;
    MyHashSet() {
    table = new  list<int>[15000];
        
    }
    
    void add(int key) {
        int i = key%15000;
        table[i].push_back(key);
        
    }
    
    void remove(int key) {
        int i = key%15000;
        table[i].remove(key);
        
    }
    
    bool contains(int key) {
        int i = key%15000;
        for(auto x : table[i])
            if(x==key)
                return true;
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */