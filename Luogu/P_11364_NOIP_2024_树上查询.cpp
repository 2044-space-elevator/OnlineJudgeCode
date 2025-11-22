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
int fa[(int)5e5 + 5][32];
vct<int> E[(int)5e5 +5];
const int N = 5E5 + 5;
int dep[N], seq[N], ST[N][32];

int lowbit(int x) {
	return x & (-x);
}

void dfs(int u, int fat) {
	dep[u] = dep[fat] + 1;
	fa[u][0] = fat;
	rep(i, 1, 31) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v : E[u]) {
		if (v == fat) continue;
		dfs(v, u);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	rrep(i, 0, 31) 
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	rrep(i, 0, 31) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i], y = fa[y][i];
		}
	}
	return fa[x][0];
}

int query(int l, int r) {
	int k = log2(r - l + 1);
	return min(ST[l][k], ST[r - (1 << k) + 1][k]);
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
	dfs(1, 0);
	repq(i, 1, n) {
		ST[i][0] = dep[lca(i, i + 1)];
	}
	int len = n - 1;
	rep(j, 1, 31) {
		rep(i, 1, len - (1 << j) + 1) {
			ST[i][j] = min(ST[i + (1 << (j - 1))][j - 1], ST[i][j - 1]);
		}
	}
	cin >> m;
	while (m--) {
		int l, r, k;
		cin >> l >> r >> k;
		if (k == 1) {
			int da = 0;
			rep(i, l, r) da = max(da, dep[i]);
			cout << da << '\n';
			continue;
		}
		int maxd = 0;
		rep(i, l, r) {
			int j = i + k - 1;
			if (j > r) break;
			maxd = max(maxd, query(i, j - 1));
		}
		cout << maxd << '\n';
	}
	return 0;
}
