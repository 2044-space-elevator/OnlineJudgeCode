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

int n, q;
const int N = 5E5 + 5;
vct<int> E[N];
int fa[N][32], dep[N], siz[N];


void dfs(int u, int fat) {
	fa[u][0] = fat;
	dep[u] = dep[fat] + 1;
	siz[u] = 1;
	rep(i, 1, 31) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v : E[u]) {
		if (v == fat) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	rrep(i, 0, 31) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	rrep(i, 0, 31) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i], y = fa[y][i];
		}
	}
	return fa[x][0];
}

int find(int x, int fat) {
	if (x == fat) return 0;
	rrep(i, 0, 31) {
		if (dep[fa[x][i]] > dep[fat]) x = fa[x][i];
	}
	return x;
}


bool check(int x, int y, int z) {
	return (lca(x, y) == y || lca(y, z) == y) && lca(y, lca(x, z)) == lca(x, z);
}

main() {
	cin >> n >> q;
	repq(i, 1, n) {
		int u, v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 0);
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		int lc = lca(a, b);
		if (c == lc) {
			cout << n - siz[find(a, lc)] - siz[find(b, lc)] << '\n';
			continue;
		} 
		if (check(a, c, lc)) {
			cout << siz[c] - siz[find(a, c)] << '\n';
			continue;
		}
		if (check(b, c, lc)) {
			cout << siz[c] - siz[find(b, c)] << '\n';
			continue;
		}
		cout << "0\n";
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
