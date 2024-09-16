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

const int N = 1e5 + 5;

int dep[N], n, q, fat[N][67];
vct<int> E[N];

void dfs(int u, int fa) {
	for (int v : E[u]) {
		if (v != fa) {
			dep[v] = dep[u] + 1;
			fat[v][0] = u;
			dfs(v, u);
		}
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	rrep(i, 0, 30) {
		if (fat[x][i] && dep[fat[x][i]] >= dep[y]) {
			x = fat[x][i];
		}
	}
	if (x == y) return x;
	rrep(i, 0, 30) {
		if (fat[x][i] != fat[y][i] && fat[x][i] && fat[y][i]) {
			x = fat[x][i];
			y = fat[y][i];
		}
	}
	return fat[x][0];
} 

int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> q;
	repq(i, 1, n) {
		int u, v; cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 0);
	rep(j, 1, 30) {
		rep(i, 1, n) {
			fat[i][j] = fat[fat[i][j - 1]][j - 1];
		}
	}
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (dis(a, b) + dis(c, d) >= dis(a, c) + dis(b, d)) {
			cout << "Y\n";
		}
		else cout << "N\n";
	}
	return 0;
}
