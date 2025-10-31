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

const int N = 5e5 + 5;
int dot[N], sz, adding_v[N];
ll ans[N], c[N], dfn[N], cnt, dfn_end[N];
bool tagged[N];
ll adding_val[N];
vct<int> E[N];

void dfs(int u) {
	dfn[u] = ++cnt;
	for (int v : E[u]) {
		dfs(v);
	}
	dfn_end[u] = cnt;
}

ll lowbit(ll x) {
	return x & (-x);
}

ll query(int x) {
	ll answ = 0;
	while (x > 0) {
		answ += c[x];
		x -= lowbit(x);
	}
	return answ;
}

int q;
void update(int x, ll val) {
	while (x <= q) {
		c[x] += val;
		x += lowbit(x);
	}
}

void solve() {
	cnt = 0;
	sz = 1;
	memset(tagged, 0, sizeof tagged);
	memset(dot, 0, sizeof dot);
	memset(c, 0, sizeof c);
	cin >> q;
	rep(i, 1, q) {
		E[i].clear();
	}
	rep(i, 1, q) {
		int op;
		cin >> op;
		if (op == 2) {
			int v; ll w;
			cin >> v >> w;
			adding_v[i] = v, adding_val[i] = w;
		}
		if (op == 1) {
			int v;
			cin >> v;
			sz++;
			E[v].push_back(sz);
			dot[i] = sz;
		}
	}	
	dfs(1);
	rrep(i, 1, q) {
		if (dot[i]) {
			// continue;
			tagged[dot[i]] = 1;
			ans[dot[i]] = query(dfn[dot[i]]);

		} else {
			int v = adding_v[i];
			int l = dfn[v], r = dfn_end[v];
			// cout << l << ' ' << r << ' ' << adding_val[i] << endl;
			update(l, adding_val[i]);
			update(r + 1, -adding_val[i]);
		}
	}
	rep(i, 1, sz) {
		if (!tagged[i]) {
			ans[i] = query(dfn[i]);
		}
		cout << ans[i] << ' ';
	}
	cout << '\n';
}




main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t; while (t--) solve();
	return 0;
}
