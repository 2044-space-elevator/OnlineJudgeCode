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

ll dp[2005][2005];
int n, m, siz[2005];
vct<pair<int, int> > E[2005];

void dfs(int u, int fat) {
	siz[u] = 1;
	dp[u][0] = dp[u][1] = 0;
	for (auto tmp : E[u]) {
		int v = tmp.first, w = tmp.second;
		if (v == fat) continue;
		dfs(v, u);
		siz[u] += siz[v];
		rrep(j, 0, min(m, siz[u])) {
			if (dp[u][j] >= 0) {
				dp[u][j] += dp[v][0] + (ll)siz[v] * (n - m - siz[v]) * w;
			}
			rrep(k, 1, min(j, siz[v])) {
				if (dp[u][j - k] < 0) continue;
				ll res = k * (m - k) + (n - m - siz[v] + k) * (siz[v] - k);
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] + res * w);
			}
		}
	}
}
main() {
	cin >> n >> m;
	repq(i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}
	if (n < 2 * m) m = n - m;
//	int t; cin >> t; while (t--) solve();
	memset(dp, -2, sizeof dp);
	dfs(1, 0);
	cout << dp[1][m];
	return 0;
}
