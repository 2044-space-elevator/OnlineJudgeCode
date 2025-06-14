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

#define int ll
struct node {
    int dis, u;
    bool operator > (const node &b) const {
        return dis > b.dis;
    }
};

priority_queue<node, vector<node>, greater<node> > que;
const int  N = 2E5 + 5;
bool vis[N];
int dis[N];
vct<pair<int, int> > E[N];
int n, m, s, q;

void dijkstra() {
    memset(dis, 127, sizeof dis);
    dis[s] = 0;
    que.push({0, s});
    while (que.size()) {
        int u = que.top().u, d = que.top().dis;
        que.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto tmp : E[u]) {
            int v = tmp.first, w = tmp.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                que.push({dis[u] + w, v});
            }
        }
    }
}


main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m >> s >> q;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    dijkstra();
    while (q--) {
        int t;
        cin >> t;
        cout << dis[t] << endl;
    }
	return 0;
}
