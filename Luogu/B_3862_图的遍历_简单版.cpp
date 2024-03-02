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

const int N = 1e3 + 5,  M = 1e3 + 5;

int cnt, head[N];
struct edge {
  int u, v, next;
}E[M];

int mxest = 0;
bool vis[N];

void dfs(int u) {
  if (vis[u]) {
    return;
  }
  vis[u] = 1;
  mxest = max(mxest, u);
  for (int i = head[u]; i; i = E[i].next) {
    int v = E[i].v;
    dfs(v);
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v;
    cin >> u >> v;
    E[++cnt] = {u, v, head[u]};
    head[u] = cnt;
  }
  rep(i, 1, n) {
    memset(vis, 0, sizeof(vis));
    mxest = 0;
    dfs(i);
    cout << mxest << ' ';
  }
	return 0;
}
