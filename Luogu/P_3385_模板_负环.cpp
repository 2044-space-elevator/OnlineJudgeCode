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

const int N = 2E3 + 5, M = 6E3 + 5;
struct edge {
  int u, v, w, next;
}E[M];
int cnt, head[M], vis[N], dis[N], tot[N];

void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}

int n, m;

bool spfa(int s) {
  memset(dis, 63, sizeof dis);
  memset(tot, 0, sizeof tot);
  dis[s] = 0;
  memset(vis, 0, sizeof vis);
  vis[s] = 1;
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int u = q.front(); q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = E[i].next) {
      int v = E[i].v;
      if (dis[v] > dis[u] + E[i].w) {
        dis[v] = dis[u] + E[i].w;
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
          tot[v]++;
          if (tot[v] == n + 1) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

void solve() {
  memset(head, 0, sizeof head);
  cnt = 0;
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    if (w >= 0) {
      add(v, u, w);
    }
  }
  m = cnt;
  if (spfa(1)) {
    RTN
    return;
  }
  RTY
}

main() {
  int t; cin >> t; while (t--) solve();
  return 0;
}