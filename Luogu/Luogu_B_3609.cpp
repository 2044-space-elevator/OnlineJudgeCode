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
int n, m, head[N], next[N], cnt, st[N], top, dfncnt, sccsum, scc[M], dfn[N], low[N];
bool vis[N];
struct edge {
  int u, v, next;
}E[M];
void add(int u, int v) {
  E[++cnt] = {u, v, head[u]};
  head[u] = cnt; 
}

vector<int> res[N];

void tarjan(int x) {
  st[++top] = x;
  dfn[x] = low[x] = ++dfncnt;
  for (int i = head[x]; i; i = E[i].next) {
    int v = E[i].v;
    if (!dfn[v]) {
      tarjan(v);
      low[x] = min(low[x], low[v]);
    } else if (!scc[v]) {
      low[x] = min(low[x], dfn[v]);
    }
  }
  if (dfn[x] == low[x]) {
    sccsum++;
    while (st[top + 1] != x) {
      int v = st[top];
      scc[v] = sccsum;
      res[sccsum].push_back(v);
      top--; 
    }
  }
}

void input() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v; cin >> u >> v;
    add(u, v);
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
  cout << sccsum << endl;
  rep(i, 1, n) {
    if (vis[scc[i]]) {
      continue;
    }
    vis[scc[i]] = 1;
    sort(res[scc[i]].begin(), res[scc[i]].end());
    for (int v : res[scc[i]]) {
      cout << v << ' ';
    }
    cout << endl;
  }
	return 0;
}
