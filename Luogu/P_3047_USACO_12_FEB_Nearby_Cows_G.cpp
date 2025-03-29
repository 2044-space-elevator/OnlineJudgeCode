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

int n, m;
int dp[(int)1e5 + 5][25];
vct<int> E[(int)1e5 + 5];

void init(int u, int fa) {
  for (int v : E[u]) {
    if (v == fa) continue;
    init(v, u);
    rep(i, 1, m) 
      dp[u][i] += dp[v][i - 1];
  }
}

void dfs(int u, int fa) {
  for (int v : E[u]) {
    if (v == fa) continue;
    rrep(i, 2, m) dp[v][i] -= dp[v][i - 2];
    rep(i, 1, m) dp[v][i] += dp[u][i - 1];
    dfs(v, u);
  }
}
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  repq(i, 1, n) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  rep(i, 1, n) cin >> dp[i][0];
  init(1, 0);
  dfs(1, 0);
  rep(i, 1, n) {
    int sum = 0;
    rep(j, 0, m) sum += dp[i][j];
    cout << sum << endl;
  }
	return 0;
}
