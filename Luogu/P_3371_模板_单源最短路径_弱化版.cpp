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

const int N = 1e4 + 5, M = 5e5 + 5;
int n, m, s, head[N], tot, vis[N], dis[N];
const int INF = 1234567890;
struct edge {
    int u, v, w, next;
}e[M];
struct node {
    int w, now;
    bool operator < (const node& x) const {
        return w > x.w;
    }
};
priority_queue<node> q;
void add(int u, int v, int w) {
    e[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}
void dijkstra() {
    rep(i, 1, n) {
        dis[i] = INF;
    }
    dis[s] = 0;
    q.push({0, s});
    while (q.size()) {
        node frt = q.top(); q.pop();
        int u = frt.now;
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                q.push({dis[v], v});
            }
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m >> s;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dijkstra();
    rep(i, 1, n) {
        if (dis[i] == INF) {
            cout << "2147483647 ";
        } else 
        cout << dis[i] << ' ';
    }
	return 0;
}
