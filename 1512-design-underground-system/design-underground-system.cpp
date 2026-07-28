class UndergroundSystem {
public:
    map<int,vector<pair<string,int>>> in;
    // map<int,vector<pair<string,int>>> out;
    map<pair<string,string>,vector<pair<int,int>>> rel;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id].push_back({stationName,t});
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [st_name,t1]=in[id].back();
        rel[{st_name,stationName}].push_back({t1,t});
        // out[id].push_back({stationName,t});
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &temp=rel[{startStation,endStation}];
        int size=temp.size();
        double sum=0;
        for(int i=0;i<size;i++){
            sum+=(temp[i].second-temp[i].first);
        }
        double avg=sum/size;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */