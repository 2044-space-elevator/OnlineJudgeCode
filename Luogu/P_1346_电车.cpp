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

int n, s, t;
const int N = 1e4;
vct<pair<int, int> > E[N];
bool vis[N];
int dis[N];

struct node {
    int u, dis;
    bool operator > (const node &b) const {
        return dis > b.dis;
    }
};

priority_queue<node, vector<node>, greater<node> > q;

void dijkstra() {
    memset(dis, 127, sizeof dis);
    dis[s] = 0;
    q.push({s, 0});
    while (q.size()) {
        int u = q.top().u, d = q.top().dis; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto tmp : E[u]) {
            int v = tmp.first, w = tmp.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v, dis[u] + w});
            }
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> s >> t;
    rep(i, 1, n) {
        int l;
        cin >> l;
        rep(k, 1, l) {
            int v;
            cin >> v;
            if (k == 1) E[i].push_back({v, 0});
            else E[i].push_back({v, 1}); 
        }
    }
    dijkstra();
    if (dis[t] >= dis[n + 1]) {
        cout << -1;
    } else cout << dis[t];
	return 0;
}
