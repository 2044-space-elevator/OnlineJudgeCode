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

int n, k;
int dp[106][106];
struct node {
  int v, w;
};
vct<node> E[106];
struct no {
  int l, r, w;
};
no tree[106];
int siz[106];
int qz[105][105];

void dfs(int u, int fa) {
  for (auto [v, w] : E[u]) {
    if (v == fa) continue;
    if (!tree[u].l) tree[u].l = v;
    else tree[u].r = v;
    qz[u][v] = qz[v][u] = w;
    dfs(v, u);
    siz[u] = siz[v] + 1;
  }
}
#define lc tree[u].l
#define rc tree[u].r
void dpro(int u, int fa) {
  if (lc)
  dpro(lc, u);
  if (rc)
  dpro(rc, u);
  rep(kk, 1, k) {
    dp[u][kk] = max(qz[lc][u] + dp[lc][kk - 1], qz[rc][u] + dp[rc][kk - 1]);
    rep(j, 1, kk - 1) {
      dp[u][kk] = max(dp[u][kk], qz[lc][u] + dp[lc][j - 1] + dp[rc][kk - 1 - j] + qz[rc][u]);
    }
  }
}
#undef lc
#undef rc

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> k;
  repq(i, 1, n) {
    int u, v, w;
    cin >> u >> v >> w;
    E[u].push_back({v, w});
    E[v].push_back({u, w});  
  }
  dfs(1, 0);
  //cout << qz[3][5];
  //cout << tree[5].l;
  //cout << tree[1].l << //tree[1].r << tree[3].l << tree[4].r;
  dpro(1, 0);
  cout << dp[1][k];
	return 0;
}
