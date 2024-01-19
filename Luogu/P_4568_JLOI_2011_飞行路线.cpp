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

const int N = 1e6 + 5, M = 5e6 + 5;
int n, m, k, s, t, vis[N], head[N], cnt, dis[N];
struct edge {
  int u, v, w, next;
}E[M];
struct node {
  int w, now;
  bool operator < (const node& x) const {
    return w > x.w;
  }
};
void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
void input() {
  cin >> n >> m >> k >> s >> t;
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
    rep(j, 1, k) {
      add(u + (j - 1) * n, v + j * n, 0);
      add(v + (j - 1) * n, u + j * n, 0);
      add(u + j * n, v + j * n, w);
      add(v + j * n, u + j * n, w);
    }
  }
  rep(i, 1, k) {
    add(t + (i - 1) * n, t + i * n, 0);
  }
}

const int INF = 1234567890;

void dijkstra() {
  priority_queue<node> q;
  memset(dis, 127, sizeof dis);
  dis[s] = 0;
  q.push({0, s});
  while (q.size()) {
    int u = q.top().now; q.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = 1;
    for (int i = head[u]; i; i = E[i].next) {
      int v = E[i].v;
      if (dis[v] > E[i].w + dis[u]) {
        dis[v] = E[i].w + dis[u];
        q.push({dis[v], v});
      }
    }
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  input();
  dijkstra();
  cout << dis[t + k * n];
	return 0;
}
