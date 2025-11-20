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

struct edge {
	int u, v; ll w;
	int typ = 0;
};

int fa[100015], n, m, k;
ll cost[15];
vct<edge> E;

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

ll ans = 1e18;

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void solve(int S) {
	rep(i ,1, n + k) {
		fa[i] = i;
	}
	ll res = 0;
	rep(i, 1, k) {
		if (S & (1 << (i - 1))) {
			res += cost[i];
		}
	}
	for (auto tmp: E) {
		if (res > ans) return;
		int u = tmp.u, v= tmp.v, typ = tmp.typ; ll w = tmp.w;
		// cout << u << ' ' << v << ' ' << typ << ' ' << w << '\n';
		if (typ) {
			if (S & (1 << (typ - 1))) {
				int fu = find(u), fv = find(v);
				if (fu == fv) continue;
				fa[fu] = fv;
				res += w;
				// cout << u << ' ' << v << ' ' << typ << ' ' << w << '\n';
			}
			continue;	
		}
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		fa[fu] = fv;
		res += w;
	}
	ans = min(ans, res);
	// cout << res << '\n';
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, m) {
		int u, v; ll w;
		cin >> u >> v >> w;
		E.push_back({u, v, w, 0});
	}
	rep(i, 1, k ){
		cin >> cost[i];
		rep(j, 1, n) {
			ll w;
			cin >> w;
			edge tmp; tmp.u = i + n; tmp.v = j; tmp.w = w; tmp.typ = i;
			// cout << tmp.u << ' ' << tmp.v << ' '<< tmp.w << '\n';
			E.push_back(tmp);
		}
	}
	// cout << cost[1];
	
	sort(E.begin(), E.end(), cmp);
	for (int S = 0; S < (1 << k); S++) {
		// cout << ans << '\n';
		if ((double)clock() / CLOCKS_PER_SEC >= 1.98) break;
		solve(S);
	}
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
