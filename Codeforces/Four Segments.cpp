#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 1000000001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

struct segment {
    pll p1;
    pll p2;
};

bool ans = 0;

bool equaldistance(segment s1, segment s2) {
    double d1 = sqrt((s1.p1.first - s1.p2.first) * (s1.p1.first - s1.p2.first) + 
                (s1.p1.second - s1.p2.second) * (s1.p1.second - s1.p2.second));
    double d2 = sqrt((s2.p1.first - s2.p2.first) * (s2.p1.first - s2.p2.first) + 
                (s2.p1.second - s2.p2.second) * (s2.p1.second - s2.p2.second));
    return d1 > 0 && d2 > 0 && d1 == d2;
}

int main() {
    vector<segment> vx;
    vector<segment> vy;
    set< pll > points;
    for (int i = 0; i < 4; ++i) {
        segment s;
        cin >> s.p1.first >> s.p1.second;
        cin >> s.p2.first >> s.p2.second;
        if (s.p1.second == s.p2.second) vx.pb(s);
        else if (s.p1.first == s.p2.first) vy.pb(s);
    }
    if (sz(vy) == 2 && sz(vx) == 2 && equaldistance(vy[0], vy[1]) && equaldistance(vx[0], vx[1])) {
        points.insert(vy[0].p1), points.insert(vy[0].p2);
        points.insert(vy[1].p1), points.insert(vy[1].p2);
        points.insert(vx[0].p1), points.insert(vx[0].p2);
        points.insert(vx[1].p1), points.insert(vx[1].p2);
        ll xmin = MAX, ymin = MAX, xmax = -MAX, ymax = -MAX;
        if (sz(points) == 4) {
            set< pll >::iterator it = points.begin();
            while (it != points.end()) {
                xmin = min(xmin, it->first);
                xmax = max(xmax, it->first);
                ymin = min(ymin, it->second);
                ymax = max(ymax, it->second);
                ++it;
            }
            if (xmin != xmax && ymin != ymax) {
                if (points.count(mp(xmin, ymin)) &&
                    points.count(mp(xmin, ymax)) &&
                    points.count(mp(xmax, ymin)) &&
                    points.count(mp(xmax, ymax))) {
                    ans = 1;
                }
            }
        }
    }
    cout << (ans? "YES" : "NO") << "\n";
}

