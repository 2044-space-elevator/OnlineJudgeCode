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

const int N = 1E5 + 5;
vct<pair<int, ll> > E[N];

ll maxe, ans, sum[N];

void dfs(int u, int fa) {
	maxe = max(maxe, sum[u]);
	for (auto tmp : E[u]) {
		int v = tmp.first;
		ll w = tmp.second;
		if (v == fa) continue;
		sum[v] = sum[u] + w;
		dfs(v, u);
		ans += w * 2;
	}
}

main() {
//	int t; cin >> t; while (t--) solve();
	int n;
	cin >> n;
	repq(i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}
	dfs(1, 0);
	cout << ans - maxe;
	return 0;
}
