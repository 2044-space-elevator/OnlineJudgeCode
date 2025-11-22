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
const int N = 5005;
int dis[N][2]; bool vis[N];
int shortest[N];

vct<pair<int, int> > E[5005];

void dijkstra() {
	memset(dis, 63, sizeof dis);
	dis[1][0] = dis[1][1] =0;
	rep(i, 1, n) {
		int u = 0, mind = dis[0][0];
		rep(j, 1, n) {
			if (!vis[j] && dis[j][0] < mind) {
				u = j, mind = dis[j][0];
			}
		}
		vis[u] = 1;
		for (auto ed : E[u]) {
			int v = ed.first, w = ed.second;	
			if (dis[v][0] > dis[u][0] + w) {
				dis[v][0] = dis[u][0] + w;
			}
		}
		for (auto ed : E[u]) {
			int v = ed.first, w = ed.second;
			if (dis[u][0] + w < dis[v][1] && dis[u][0] + w != dis[v][0]) {
				dis[v][1] = dis[u][0] + w;
			}
			if (dis[u][1] + w < dis[v][1] && dis[u][1] + w != dis[v][0]) {
				dis[v][1] = dis[u][1] + w;
			}
			// cout << v << ' ' << dis[v][0] + w * 2 << '\n';
			dis[v][1] = min(dis[v][1], dis[v][0] + shortest[v] * 2);
		}
	}
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	memset(shortest, 63, sizeof shortest);
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u].push_back({v, w});
		E[v].push_back({u, w});
		shortest[u] = min(shortest[u], w);
		shortest[v] = min(shortest[v], w);
	}
	dijkstra();
	// rep(i, 1, n) cout << dis[n][1] << ' ' ;
	cout << dis[n][1];
	return 0;
}
