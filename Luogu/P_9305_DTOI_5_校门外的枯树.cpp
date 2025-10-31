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

int k;
const int N = 1E5 + 5;
vct<pair<int ,int> > E[N];
int m[N], lef[N], dfn_mx[N], dfn_mn[N], cnt, dfn_belonged[N], chain_sum[N];

void dfs_firs(int u) {
	dfn_mn[u] = cnt;
	for (auto tmp : E[u]) {
		int v = tmp.first, w = tmp.second;
		chain_sum[v] = chain_sum[u] + w;
		dfs_firs(v);
		m[u] = m[u] + m[v] + w;
	}
	if (!E[u].size()) {
		++cnt;
		dfn_belonged[cnt] = u;
	}
	dfn_mx[u] = cnt;
}

void dfs_seco(int u) {
	int sum = 0;
	for (auto tmp : E[u]) {
		int v = tmp.first, w = tmp.second;
		lef[v] = lef[u] + sum + w;
		dfs_seco(v);
		sum += m[v] + w;
	}
}

int query(int from, int to) {
	int wei_chain = chain_sum[to] - chain_sum[from];
	int left = lef[to] - lef[from] - wei_chain;
	return left - (m[from] - left - wei_chain);
}

void solve() {
	memset(dfn_belonged, 0, sizeof dfn_belonged);
	memset(dfn_mx, 0, sizeof dfn_mx);
	memset(dfn_mn, 0, sizeof dfn_mn);
	memset(lef, 0, sizeof lef);
	memset(m, 0, sizeof m);
	memset(chain_sum, 0, sizeof chain_sum);
	lef[1] = chain_sum[1] = 0;
	cnt = 0;
	int n;
	cin >> n;
	rep(i, 1, n) {
		E[i].clear();
		m[i] = 0;
	}
	rep(i, 1, n) {
		int x;
		cin >> x;
		rep(j, 1, x) {
			int v, w;
			cin >> v >> w;
			E[i].push_back({v, w});
		}
	}
	dfs_firs(1);
	dfs_seco(1);
	// cout << chain_sum[5];
	rep(i, 1, n) {
		if (k == 1 && i != 1) {
			continue;
		}
		int l = dfn_mn[i], r = dfn_mx[i] - 1;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (query(i, dfn_belonged[mid]) >= 0) {
				r = mid;
			} else l = mid;
		}
		cout << min(abs(query(i, dfn_belonged[l])), abs(query(i, dfn_belonged[r]))) << ' ';
	}
	cout << '\n';
}


main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t >> k; while (t--) solve();
	
	return 0;
}
