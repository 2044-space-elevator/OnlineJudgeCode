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
	int v;
	ll l, r;
};
const int N = 1E6 + 5;
vct<edge> E[N];
ll lef[(int)5e5 + 5], righ[(int)5e5 + 5], addition[(int)5e5 + 5];
ll all_d[3 * N], dif[3 * N];

void dfs(int u) {
	for (auto tmp : E[u]) {
		int v = tmp.v; ll l = tmp.l, r = tmp.r;
		lef[v] = max(lef[u], l - addition[u]);
		righ[v] = min(righ[u], r - addition[u]);
		addition[v] += addition[u];
		dfs(v);	
	}
}


// void query(int u, ll v) {
// 	cnt++;
// 	for (auto tmp : E[u]) {
// 		ll l = tmp.l, r = tmp.r;
// 		if (lef[tmp.v] <= v && v <= righ[tmp.v]) {
// 			query(tmp.v, v);
// 		}
// 	}
// }

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/Lenovo/Desktop/calc6.in", "r", stdin);
		freopen("C:/Users/Lenovo/Desktop/calc6.out", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	lef[1] = -1e18, righ[1] = 1e18;
	rep(i, 2, n) {
		int fa; ll l, r;
		cin >> fa >> l >> r;
		E[fa].push_back({i, l, r});
		lef[i] = -1e18;
		righ[i] = 1e18;
 	}
	rep(i, 1, n) {
		char ch;
		cin >> ch;
		cin >> addition[i];
		if (ch == '-')
			addition[i] = -addition[i];
	}
	dfs(1);
	int cnt = 0;
	rep(i, 1, n) {
		if (lef[i] > righ[i]) continue;
		all_d[++cnt] = lef[i];
		all_d[++cnt] = righ[i];
		all_d[++cnt] = righ[i] + 1;
	}
	sort(all_d + 1, all_d + cnt + 1);
	cnt = unique(all_d + 1, all_d + cnt + 1) - (all_d + 1);
	rep(i, 1, n) {
		if (lef[i] > righ[i]) continue;
		lef[i] = lower_bound(all_d + 1, all_d + cnt + 1, lef[i]) - all_d;
		righ[i] = lower_bound(all_d + 1, all_d + cnt + 1, righ[i]) - all_d;
		dif[lef[i]]++;
		dif[righ[i] + 1]--;
	}
	rep(i, 1, cnt) {
		dif[i] += dif[i - 1];
	}
	while (m--) {
		ll v;
		cin >> v;
		int pos = lower_bound(all_d + 1, all_d + cnt + 1, v) - all_d;
        
        if (pos <= cnt && all_d[pos] == v) {
            cout << dif[pos] << '\n';
        } else {
            if (pos > 1) {
                cout << dif[pos - 1] << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
