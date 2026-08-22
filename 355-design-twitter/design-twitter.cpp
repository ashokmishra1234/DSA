class Twitter {
public:
    map<int,unordered_set<int>> follow_id;
    map<int,vector<pair<int,int>>> tweets_id;
    int timestamp;

    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets_id[userId].push_back({timestamp,tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto [time,tweet_id]:tweets_id[userId]){
            pq.push({time,tweet_id});
        }
        for(auto id:follow_id[userId]){
            for(auto [time,tweet_id]:tweets_id[id]){
            pq.push({time,tweet_id});
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follow_id[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_id[followerId].erase(followeeId);
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