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

const int N = 1e5 + 5, M = 1e5 + 5;
int n, m, head[N], head2[N], cnt, cnt2, st[N], top, dfncnt, sccsum, scc[M], dfn[N], low[N], MAX[N], dp[N];
bool vis[N];
struct edge {
  int u, v, next;
}E[M], E2[M];

void tarjan(int x) {
  st[++top] = x;
  dfn[x] = low[x] = ++dfncnt;
  for (int i = head[x]; i; i = E[i].next) {
    int v = E[i].v;
    if (!dfn[v]) {
      tarjan(v);
      low[x] = min(low[x], low[v]);
    }
    else if (!scc[v]) {
      low[x] = min(low[x], dfn[v]);
    }
  }
  if (dfn[x] == low[x]) {
    sccsum++;
    int v ;
    while (v = st[top]) {
      scc[v] = sccsum;
      MAX[sccsum] = max(MAX[sccsum], v);
      top--;
      if (x == v) {
        break;
      }
    }
  }
}

void input() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v; cin >> u >> v;
    E[++cnt] = {u, v, head[u]};
    head[u] = cnt;
  }
}

void dfs(int x) {
  if (dp[x]) return;
  dp[x] = MAX[x];
  for (int i = head2[x]; i; i = E2[i].next) {
    int v = E2[i].v;
    if (!dp[v]) {
      dfs(v);
    }
    dp[x] = max(dp[x], dp[v]);
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  input();
  rep(i, 1, n) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }
  rep(i, 1, m) {
    int u = scc[E[i].u], v = scc[E[i].v];
    if (u != v) {
      E2[++cnt2] = {u, v, head2[u]};;
      head2[u] = cnt2;
    }
  }
  rep(i, 1, sccsum) {
    if (!dp[i]) {
      dfs(i);
    }
  }
  rep(i, 1, n) cout << dp[scc[i]] << ' ';
	return 0;
}
