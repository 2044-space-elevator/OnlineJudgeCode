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

bool G[155][155], vis[155], ans = 1;
vct<int> E[155];
int n, m;

void dfs(int u) {
  for (int i = 1; i <= n; i++) {
    if (G[u][i] && !vis[i]) {
      vis[i] = 1;
      dfs(i);
    } 
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(j, 1, m) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    G[u][v] = G[v][u] = 1;
    E[u].push_back(v);
  }
  rep(i, 1, n) {
    sort(E[i].begin(), E[i].end());
    for (int j : E[i]) {
      G[i][j] = G[j][i] = 0;
      ans = 1;
      memset(vis, 0, sizeof vis);
      vis[j] = 1;
      dfs(j);
      rep(k, 1, n) {
        if (!vis[k]) {
          cout << i << ' ' << j << endl;
          break;
        }
      }
      G[i][j] = G[j][i] = 1;
    }
  }
	return 0;
}
