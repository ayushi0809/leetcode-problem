class BrowserHistory {
    struct Node{
        string str;
        Node* prev;
        Node* next;
        Node(): str(""), prev(nullptr), next(nullptr){};
        Node(string val): str(val), prev(nullptr), next(nullptr){};
    };
public:
    Node* history;
    Node* current;
    BrowserHistory(string homepage) {
        history = new Node(homepage);
        current = history;
        
    }
    
    void visit(string url) {
        Node* q = new Node(url);
            Node* x = current->next;
        current->next=q;
        q->prev = current;
            q->next = NULL;
            current = q;
        
    }
    
    string back(int steps) {
        Node* p = current;
        int i =0;
        cout<<current->str<<endl;
        if(current->prev){
            cout<<current->prev->str<<endl;
        }
        while(p->prev != NULL && steps>0){
            //cout<<p->str<<endl;
            
            p=p->prev;
            steps--;
            
        }
        current =p;
        cout<<steps<<endl;
       
        return p->str;
        
    }
    
    string forward(int steps) {
        Node* q = current;
        while(q->next != NULL && steps>0){
            q=q->next;
            steps--;
        }
        current = q;
        return q->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */