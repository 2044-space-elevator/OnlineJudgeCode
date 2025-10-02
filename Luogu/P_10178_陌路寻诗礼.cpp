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

const int N = 3E5 + 5;
vct<pair<int, int> > E[N];
int ans[N], dis[N];
bool vis[N];

struct node {
    int u, dis;
    bool operator < (const node &b) const {
        return dis > b.dis;
    }
};

int n, m, k;

bool dijkstra() {
    memset(vis, 0, sizeof vis);
    memset(dis, 62, sizeof dis);
    priority_queue<node> q;

    dis[1] = 0;
    q.push({1, 0});
    int mx = 0;
    while (q.size()) {
        int u = q.top().u, di = q.top().dis;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto tmp : E[u]) {
            int v = tmp.first, id = tmp.second;
            if (dis[v] == di + 1) {
                mx = max(mx, ++ans[id]);
            }
            if (dis[v] > di + 1) {
                dis[v] = di + 1;
                q.push({v, dis[v]});
            } 
        }
    }
    return mx <= k;
}

void solve() {
    cin >> n >> m >> k;
    rep(i, 1, n) {
        E[i].clear();
    }
    rep(i, 1, m) {
        ans[i] = 1;
    }
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        E[u].push_back({v, i});
    }
    if (dijkstra()) {
        cout << "Yes\n";
        rep(i, 1, m) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    } else cout << "No\n";

}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
