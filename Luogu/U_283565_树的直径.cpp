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

vct<int> E[(int)2e5 + 5];

int res = 0, dp[(int)2e5 + 5];

void dfs(int u, int fa) {
  for (int v : E[u]) {
    if (v == fa) {
      continue;
    }
    dp[v] = dp[u] + 1;
    if (dp[v] > dp[res]) {
      res = v;
    }
    dfs(v, u);
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) {
    int a, b;
    cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  dfs(1, 0);
  dp[res] = 0;
  dfs(res, 0);
  cout << dp[res];
	return 0;
}
