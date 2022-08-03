class MyCalendar {
public:
    vector<pair<int,int>>st;
    int i =0;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(i==0){
            st.push_back({start,end});
            i++;
            return true;
        }
        for(int j =0; j<i; j++){
            auto it = st[j];
            if(start<it.second && it.first<end){
                return false;
            }
        }
        st.push_back({start,end});
        i++;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */