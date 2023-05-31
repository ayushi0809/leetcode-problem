class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> checkin;
    unordered_map<string, pair<int,int>> checkout;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
        
        
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = checkin[id];
        checkin.erase(id);
        string startstation = it.first;
        int starttime = it.second;
        string s = startstation+","+stationName;
        checkout[s].first++ ;
        checkout[s].second = checkout[s].second +  (t-starttime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& [count, sum] = checkout[startStation + "," + endStation];
        return (double)sum / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */