class UndergroundSystem {
public:
    map<int, vector<pair<string, int > > > db1;
    map<string, map<string, pair<int, int > > > db2;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        db1[id].push_back(make_pair(stationName, t));
    }
    
    void checkOut(int id, string stationName, int t) {
        vector<pair<string, int > > v = db1[id];
        pair<string, int> last = v[v.size() - 1];
        db2[last.first][stationName].first+=(t-last.second);
        db2[last.first][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = db2[startStation][endStation];
        return (double) (p.first/(double) p.second);
    }
};