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

struct node {
    ll u, dis;
    bool operator > (const node &b) const {
        return dis > b.dis;
    }
};

priority_queue<node, vector<node>, greater<node> > q;
int n, m, s, t;
const int N = 2505;
vct<pair<int, int> > E[N];
bool vis[N];
ll dis[N];

void dijkstra() {
    memset(dis, 127, sizeof dis);
    q.push({s, 0});
    dis[s] = 0;
    while (q.size()) {
        int u = q.top().u, w = q.top().dis; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (pair<int, int> pp : E[u]) {
            int v = pp.first, di = pp.second;
            if (dis[v] > w + di) {
                dis[v] = w + di;
                q.push({v, dis[v]});
            }
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m >> s >> t;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    dijkstra();
    cout << dis[t];
	return 0;
}
