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
stg s;
const int N = 2E6 + 5;
int pi[N];
vct<int> E[N];
int fa[N][31], dep[N];

void dfs(int u, int fat) {
	dep[u] = dep[fat] + 1;
	fa[u][0] = fat;
	rep(i, 1, 30) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v : E[u]) {
		if (v == fat) continue;
		dfs(v, u);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	rrep(i, 0, 30) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	rrep(i, 0, 30) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i], y = fa[y][i];
		}
	}
	return fa[x][0];
}


main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	
	repq(i, 1, s.size()) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	rep(i, 1, s.size()) {
		E[pi[i - 1]].push_back(i);
	}
	dfs(0, 0);
	int m; cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		int lc = lca(x, y);
		if (x == lc || y == lc) {
			cout << fa[lc][0] << '\n';
		} else cout << lc << '\n';
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
