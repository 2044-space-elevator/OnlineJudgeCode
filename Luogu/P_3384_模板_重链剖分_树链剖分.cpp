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
int dfn_end[N], dfn[N], cnt, n, m, root, top[N], fa[N][32], dep[N], arr[N];
ll mod, tr[N << 2], lazy[N << 2];

#define lc (p * 2)
#define rc (p * 2 + 1)

void pushDown(int p, int pl, int pr) {
	lazy[p] %= mod;
	int mid = (pl + pr) / 2;
	if (lazy[p]) {
		lazy[lc] = (lazy[lc] + lazy[p]) % mod;
		lazy[rc] = (lazy[rc] + lazy[p]) % mod;
		tr[lc] = (tr[lc] + (mid - pl + 1) * lazy[p] % mod) % mod;
		tr[rc] = (tr[rc] + (pr - mid) * lazy[p] % mod) % mod;
		lazy[p] = 0;
	}
}

void pushUp(int p) { tr[p] = (tr[lc] + tr[rc]) % mod; }

void update(int p, int pl, int pr, int l, int r, ll k) {
	if (l <= pl && pr <= r) {
		tr[p] = (tr[p] + (pr - pl + 1) * k % mod) % mod;
		lazy[p] += k;
		return;
	}
	int mid = (pl + pr) / 2;
	pushDown(p, pl, pr);
	if (l <= mid) update(lc, pl, mid, l, r, k);
	if (r > mid) update(rc, mid + 1, pr, l, r, k);
	pushUp(p);
}

ll query(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) return tr[p];
	int mid = (pl + pr) / 2;
	ll ans = 0;
	pushDown(p, pl, pr);
	if (l <= mid) ans = (ans + query(lc, pl, mid, l, r)) % mod;
	if (r > mid) ans = (ans + query(rc, mid + 1, pr, l, r)) % mod;
	pushUp(p);
	return ans;
}

vct<int> E[N];
int siz[N];
int wv[N];

void dfs_siz(int u, int fat) {
	dep[u] = dep[fat] + 1;
	fa[u][0] = fat;
	rep(i, 1, 31) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	siz[u] = 1;
	int mx = 0;
	for (int v : E[u]) {
		if (v == fat) continue;
		dfs_siz(v, u);
		if (siz[v] > mx) {
			mx = siz[v], wv[u] = v;
		}
		siz[u] += siz[v];
	}
}

void dfs_wv(int u, int fa, int tp) {
	dfn[u] = ++cnt;
	top[u] = tp;
	if (wv[u])
		dfs_wv(wv[u], u, tp);
	for (int v : E[u]) {
		if (v == fa || v == wv[u]) continue;
		dfs_wv(v, u, v);
	}
	dfn_end[u] = cnt;
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m >> root >> mod;
	rep(i, 1, n) {
		cin >> arr[i];
	}
	repq(i, 1, n) {
		int u, v;
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);	
	}
	dfs_siz(root, 0);
	dfs_wv(root, 0, root);
	// rep(i, 1, n)  cout << dfn[i] << ' ' << dfn_end[i] << endl;
	rep(i, 1, n) update(1, 1, n, dfn[i], dfn[i], arr[i]);
	while (m--) {
		int typ;
		cin >> typ;
		if (typ == 1) {
			int x, y, z;
			cin >> x >> y >> z;
			while (top[x] != top[y]) {
				if (dep[top[x]] < dep[top[y]]) swap(x, y);
				update(1, 1, n, dfn[top[x]], dfn[x], z);
				x = fa[top[x]][0];
			}
			if (dep[x] > dep[y]) swap(x, y);
			update(1, 1, n, dfn[x], dfn[y], z);
		} if (typ == 2) {
			int x, y;
			cin >> x >> y;
			ll ans = 0;
			while (top[x] != top[y]) {
				if (dep[top[x]] < dep[top[y]]) swap(x, y);
				ans = (ans + query(1, 1, n, dfn[top[x]], dfn[x]))  % mod;
				x = fa[top[x]][0];
			}
			if (dep[x] > dep[y]) swap(x, y);
			ans = (ans + query(1, 1, n, dfn[x], dfn[y])) % mod;
			cout << ans << '\n';
		} if (typ == 3) {
			int x, z;
			cin >> x >> z;
			update(1, 1, n, dfn[x], dfn_end[x], z);
		} if (typ == 4) {
			int x;
			cin >> x;
			cout << query(1, 1, n, dfn[x], dfn_end[x]) << '\n';
		}
	}
	return 0;
}
