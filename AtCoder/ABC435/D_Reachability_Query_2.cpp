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

const int N = 5E5 + 5;
vct<int> E[N];
bool vis[N];

void dfs(int u) {
	vis[u] = 1;
	for (int v : E[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

main() {
//	int t; cin >> t; while (t--) solve();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		E[v].push_back(u);
	}
	int q;
	cin >> q;
	while (q--) {
		int typ, qu;
		cin >> typ >> qu;
		if (typ == 1) { if (!vis[qu]) dfs(qu); }
		else {
			if (vis[qu]) cout << "Yes\n";
			else cout << "No\n";
		}
	}
return 0;
}
