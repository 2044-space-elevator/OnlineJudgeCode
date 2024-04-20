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

const int N = 3e6 + 5, M = 3e6 + 5;
int head[N], dis[N], n, m, cnt;
bool vis[N];
struct edge {
  int u, v, w, next;
}E[M];
void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
struct node {
  int w, now;
  bool operator < (const node &x) const {
    return w > x.w;
  }
};
priority_queue<node> q;

void dijkstra(int s) {
  rep(i, 1, 2 * n) {
    dis[i] = INT_MAX;
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
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v + n, u + n, w);
  }
  dijkstra(1);
  int sum = 0;
  rep(i, 1, n) {
    sum += dis[i];
  }
  dijkstra(n + 1);
  rep(i, n + 1, 2 * n) {
    sum += dis[i];
  }
  cout << sum;
	return 0;
}
