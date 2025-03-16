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

int n, ri[(int)6e3 + 5], f[(int)6e3 + 5][2];
vct<int> g[6005];

void dfs(int u, int fa) {
  f[u][1] = ri[u];
  for (auto v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    f[u][1] += f[v][0];
    f[u][0] += max(f[v][0], f[v][1]);
  }
}
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) cin >> ri[i];
  repq(i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << max(f[1][0], f[1][1]) << endl;

	return 0;
}
