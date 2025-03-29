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

int dep[(int)1e6 + 5];
ll dp[(int)1e6 + 5];
int siz[(int)1e6 + 5];
int n;
vct<int> E[(int)1e6 + 5];
void dfs1(int u, int fa) {
  siz[u] = 1;
  dep[u] = dep[fa] + 1;
  for (int v : E[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    siz[u] += siz[v];
  }
}

void dfs2(int u, int fa) {
  for (int v : E[u]) {
    if (v == fa) continue;
    dp[v] = dp[u] - siz[v] + n - siz[v];
    dfs2(v, u);
  }
}
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  repq(i, 1, n) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs1(1, 0);
  rep(i, 1, n) dp[1] += dep[i];
  dfs2(1, 0);
  ll ans = 0;
  int ind = 0;
  rep(i, 1, n) {
    if (ans < dp[i]) {
      ans = dp[i];
      ind = i;
    }
  }
  cout << ind;
	return 0;
}
