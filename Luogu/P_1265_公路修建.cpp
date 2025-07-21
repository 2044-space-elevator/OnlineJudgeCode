#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(int v=b;v<=e;v++)
#define repq(v,b,e) for(int v=b;v<e;v++)
#define rrep(v,e,b) for(int v=b;v>=e;v--)
#define rrepq(v,e,b) for(int v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}
int n;
pair<double, double> loc[5005];
double dist[5005];
bool vis[5005];
vct<pair<int, double> > E[5005];

struct qn {
    int u;
    double d;
    bool operator < (const qn & b) const {
        d < b.d;
    }
};

priority_queue<qn> q;

double dis(int x, int y) {
    return sqrt((loc[x].first - loc[y].first) * (loc[x].first - loc[y].first) + (loc[x].second - loc[y].second) * 
        (loc[x].second - loc[y].second));
}

double res = 0;

void Prim() {
    memset(dist, 127, sizeof dist);
    int cnt = 0;
    dist[1] = 0;
    q.push({1, 0});
    while (q.size()) {
        if (cnt >= n) break;
        int u = q.top().u; double d = q.top().d; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ++cnt;
        res += d;
        for (auto tmp : E[u]) {
            int v = tmp.first; double w = tmp.second;
            if (w < dist[v]) {
                qn tmp;
                tmp.u = v, tmp.d = w;
                dist[v] = w, q.push(tmp);
            }
        }
    }
}



main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    rep(i, 1, n) {
        cin >> loc[i].first >> loc[i].second;
    }
    repq(i, 1, n) {
        double ttmp = 1e9; int tind = 0;
        rep(j, 1, n) {
            if (i == j) continue;
            E[i].push_back({j, dis(i, j)});
            E[j].push_back({i, dis(i, j)});
        }
    }
    Prim();
    printf("%.2lf", res);
	return 0;
}
