class MovingAverage {
    vector<int> v;
    int i, n;
    double sum;
    bool is_full;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        v.resize(size);
        i = 0, n = size;
        is_full = false;
    }
    
    double next(int val) {
        if (n == 0) {
            return 0.0;
        }
        double fact = 1.0;
        if (!is_full) {
            sum += val;
            v[i++] = val;
            fact = (double) i;
        } else {
            sum -= v[i];
            sum += val;
            v[i++] = val;
            fact = (double) n;
        }
        is_full |= (i == n);
        i %= n;
        return (double) (sum / fact);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */