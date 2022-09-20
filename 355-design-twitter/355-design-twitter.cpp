class Twitter {
public:
    unordered_map<int,unordered_set<int>>follower;
    unordered_map<int,vector<pair<int,int>>>tweets;
    int count;
    Twitter() {
        count =0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        auto it = tweets[userId];
          int k =10;  
        vector<int>ans;
        for(int i =0; i<it.size(); i++){
            pq.push(it[i]);
        }
        auto it1 = follower[userId];
        for(auto a = it1.begin(); a != it1.end(); a++){
            auto v= tweets[*a];
            for(int j =0; j<v.size(); j++){
                pq.push(v[j]);
            }
        }
        while(k && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */