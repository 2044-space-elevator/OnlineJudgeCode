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
int n, m, st[N], top, dfncnt, sccsum, dfn[N], low[N];
bool vis[N];
vct<int> E[N];

void tarjan(int x) {
  st[++top] = x;
  dfn[x] = low[x] = ++dfncnt;
  for (int v : E[x]) {
    if (!dfn[v]) {
      tarjan(v);
      low[x] = min(low[x], low[v]);
    } else if (!vis[v]) {
      low[x] = min(low[x], dfn[v]);
    } 
  }
  if (dfn[x] == low[x]) {
    sccsum++;
    while (st[top + 1] != x) {
      int v = st[top];
      top--;
      vis[v] = 1;
    }
  }
}

void input() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v; cin >> u >> v; E[u].push_back(v);
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
	return 0;
}
