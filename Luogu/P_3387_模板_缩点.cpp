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
const int N = 1e4 + 5, M = 1e5 + 5;
int n, m, head[N], cnt, st[N], top, dfncnt;
int pts[N], circle_belong[N], head2[N]; // circle_belong: 环的归属
int dfn[N], low[N];
bool vis[N];
struct edge {
  int u, v, next;
}E[M], E2[M];
void add(int u, int v) {
  E[++cnt] = {u, v, head[u]};
  head[u] = cnt; 
}
void input() {
  cin >> n >> m;
  rep(i, 1, n) {
    cin >> pts[i];
  }
  rep(i, 1, m) {
    int u, v; cin >> u >> v;
    add(u, v);
  }
}

void tarjan(int x) {
  st[++top] = x;
  dfn[x] = low[x] = ++dfncnt;
  for (int i = head[x]; i; i = E[i].next) {
    int v = E[i].v;
    if (!dfn[v]) {
      tarjan(v);
      low[x] = min(low[x], low[v]);
    } else if (!vis[v]) {
      low[x] = min(low[x], dfn[v]);
    }
  }
  if (dfn[x] == low[x]) {
    int v;
    while (v = st[top--]) {
      circle_belong[v] = x;
      vis[v] = 1;
      if (x == v) {
        break;
      }
      pts[x] += pts[v];
    }
  }
}

int cnt2, in[N], dist[N];
main() {
//	int t; cin >> t; while (t--) solve();
  input();
  rep(i, 1, n) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  rep(i, 1, m) {
    int u = circle_belong[E[i].u], v = circle_belong[E[i].v];
    if (u != v) {
      E2[++cnt2] = {u, v, head2[u]};
      head2[u] = cnt2;
      in[v]++;
    }
  }
  queue<int> q;
  rep(i, 1, n) {
    if (circle_belong[i] == i && !in[i]) {
      q.push(i);
      dist[i] = pts[i];
    }
  }
  while (q.size()) {
    int frt = q.front(); q.pop();
    for (int i = head2[frt]; i; i = E2[i].next) {
      int v = E2[i].v;
      dist[v] = max(dist[v], dist[frt] + pts[v]);
      in[v]--;
      if (!in[v]) {
        q.push(v);
      }
    }
  }
  int ans = 0;
  rep(i, 1, n) {
    ans = max(ans, dist[i]);
  }
  cout << ans;
	return 0;
}
