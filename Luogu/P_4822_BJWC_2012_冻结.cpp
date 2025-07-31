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

const int N = 55;
int dis[55][55], n, m, k;
vct<pair<int, int> > E[N];
bool vis[55];

struct node {
    int u, kused, dis;
    bool operator > (const node &b) const {
        return b.dis < dis;
    }
};

priority_queue<node, vector<node>, greater<node>> q;

void dijkstra() {
    memset(dis, 127, sizeof dis);
    dis[1][0] = 0;
    q.push({1, 0, 0});
    while (q.size()) {
        int u = q.top().u, kused = q.top().kused; q.pop();
        for (auto tmp : E[u]) {
            int v = tmp.first, w = tmp.second;
            if (kused < k && dis[v][kused + 1] > dis[u][kused] + (w / 2)) {
                dis[v][kused + 1] = dis[u][kused] + w / 2;
                q.push({v, kused + 1, dis[v][kused + 1]});
            }
            if (kused <= k && dis[v][kused] > dis[u][kused] + w) {
                dis[v][kused] = dis[u][kused] + w;
                q.push({v, kused, dis[v][kused]});
            }
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m >> k;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    dijkstra();
    int ans = 1e9;
    rep(i, 0, k) {
        ans = min(ans, dis[n][i]);
    }
    cout << ans;
	return 0;
}
