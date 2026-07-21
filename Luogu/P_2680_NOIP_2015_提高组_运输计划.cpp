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
const int N = 3E5 + 5;
int fa[N][30], dep[N], pref[N], dfn[N], cnt;

int n, m;
struct node {
	ll v, w;
};
vct<node> E[N];
ll path[N];
ll dif[N];

void dfs(int u, int fat) {
	dfn[++cnt] = u;
	dep[u] = dep[fat] + 1;
	fa[u][0] = fat;
	for (int i = 1; i <= 29; i++) 
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto tmp : E[u]) {
		int v = tmp.v;
		if (v == fat) continue;
		pref[v] = pref[u] + tmp.w;
		path[v] = tmp.w;
		dfs(v, u);
	}
}

struct ques {
	int u, v, dis, fa;
} ys[N];
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 29; i >= 0; i--) {
		if (dep[fa[u][i]] >= dep[v]) {
			u = fa[u][i];
		}
	}
	if (u == v) return u;
	for (int i = 29; i >= 0; i--) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i]; v = fa[v][i];
		}
	}
	return fa[u][0];
}

bool check(int x) {
	memset(dif, 0, sizeof dif);
	int cnt = 0; int res = 0;
	rep(i, 1, m) {
		if (ys[i].dis > x) {
			++cnt; res = max(res, ys[i].dis);
			dif[ys[i].u]++; dif[ys[i].v]++;
			dif[ys[i].fa] -= 2;
		}
	}
	if (!cnt) return 1;
	rrep(i, 1, n) dif[fa[dfn[i]][0]] += dif[dfn[i]];
	rep(i, 2, n) {
		if (dif[i] == cnt && res - path[i] <= x) return 1;
	}	
	return 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	repq(i, 1, n ){
		int u, v, w;
		cin >> u >> v>> w;
		E[u].push_back({v, w});
		E[v].push_back({u, w});
	}
	dfs(1, 0);
	ll ans = 0;
	rep(i, 1, m) {
		int x, y;
		cin >> x >> y;
		ys[i].fa = lca(x, y);
		ys[i].dis = pref[x] + pref[y] - 2 * pref[ys[i].fa];
		ys[i].u = x; ys[i].v = y;	
	}
	int l = 0, r = 5e8;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1, ans = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}