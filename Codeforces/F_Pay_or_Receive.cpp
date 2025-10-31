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

int cnt;
int belonged[N];
ll dis[N];
bool loop[N];
vct<pair<int, ll> > E[N];

void dfs(int u) {
	belonged[u] = cnt;
	for (auto tmp : E[u]) {
		int v = tmp.first; ll w = tmp.second;
		if (!belonged[v]) {
			dis[v] = dis[u] + w;
			dfs(v);
		} else if (dis[v] != dis[u] + w) {
			loop[cnt] = 1;
		} 
	}
}

main() {
//	int t; cin >> t; while (t--) solve();
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u].push_back({v, w});
		E[v].push_back({u, -w});
	}
	rep(i ,1, n) {
		if (!belonged[i]) { 
			cnt++;
			dfs(i);
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (belonged[u] != belonged[v]) {
			cout << "nan\n";
			continue;
		}
		ll a1 = dis[u], a2 = dis[v];
		if (loop[belonged[u]]) {
			cout << "inf\n";
			continue;
		}
		cout << a2 - a1 << '\n';
	}
	return 0;
}
