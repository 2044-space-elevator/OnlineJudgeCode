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

const int N = 2e5 + 5;
ll dp[N], deg[N], n, siz[N];
vct<pair<int, ll> > E[N];

void dfs1(int u, int fa) {
	for (auto tmp : E[u]) {
		int v = tmp.first; ll w = tmp.second;
		if (v == fa) continue;
		dfs1(v, u);
		if (deg[v] > 1) siz[u] += min(w, siz[v]);
		else siz[u] += w;
	}
}

void dfs2(int u, int fa) {
	for (auto tmp : E[u]) {
		int v = tmp.first; ll w = tmp.second;
		if (v == fa) continue;
		if (deg[u] == 1) dp[v] = siz[v] + w;
		else if (deg[v] > 1) dp[v] = min(dp[u] - min(siz[v], w), w) + siz[v];
		else dp[v] = min(w, dp[u] - w) + siz[v];
		dfs2(v, u);
	}
}

void solve() {
	cin >> n;
	memset(dp, 0, sizeof dp);
	memset(deg, 0, sizeof deg);
	memset(siz, 0, sizeof siz);	
	rep(i, 1, n) E[i].clear();
	repq(i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u].push_back({v, w});
		E[v].push_back({u, w});
		deg[u]++, deg[v]++;
	}
	dfs1(1, 0);
	dp[1] = siz[1];
	ll ans = dp[1];
	dfs2(1, 0);
	rep(i, 2, n) ans = max(ans, dp[i]);
	cout << ans << '\n';
}

main() {
	
	int t; cin >> t; while (t--) solve();
	return 0;
}
