class StockSpanner {
public:
    vector< pair<int, int > > v;
    
    StockSpanner() {}
    
    int next(int price) {
        if (v.size() == 0) {
            v.push_back({price, 1});
            return 1;
        } else {
            int cnt = 1;
            int i = v.size() - 1;
            while (i >= 0) {
                pair<int, int> x = v[i];
                if (x.first <= price) {
                    //cout << "x.first -> " << x.first << "  x.second -> " << x.second << endl;
                    cnt += x.second;
                    i -= x.second;
                } else break;
            }
            v.push_back({price, cnt});
            return cnt;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */