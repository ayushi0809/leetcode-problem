class MedianFinder {
public:
    priority_queue<int>min_values;
    priority_queue<int,vector<int>, greater<int>>max_values;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_values.push(num);
        if(min_values.size()-max_values.size()>1){
            max_values.push(min_values.top());
            min_values.pop();
        }
       if(!min_values.empty() && !max_values.empty() && min_values.top()>max_values.top()){
             max_values.push(min_values.top());
             min_values.pop();
           if(max_values.size()-min_values.size()>1){
            min_values.push(max_values.top());
            max_values.pop();
        }
            
        }
    }
    
    double findMedian() {
        if(min_values.size()==max_values.size()){
            return (min_values.top()+max_values.top())/2.0;
        }
        if(min_values.size()>max_values.size()){
            return min_values.top();
        }
        return max_values.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */