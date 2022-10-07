class MyCalendarTwo {
public:
    vector<pair<int,int>>v1;
    vector<pair<int,int>>v2;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(int i =0; i<v2.size(); i++){
            auto it = v2[i];
            if(it.first<end && start<it.second)return false;
        }
        
        for(int i =0; i<v1.size(); i++){
            auto it = v1[i];
            if(it.first<end && start<it.second){
                v2.push_back({max(start,it.first), min(end, it.second)});
            }
        }
        v1.push_back({start,end});
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */