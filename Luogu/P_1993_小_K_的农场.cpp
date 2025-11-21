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

ll n, m, dis[5005], cnt[5005];
vct<pair<int, int> > E[5005];
bool vis[5005];
queue<int> q;

bool spfa(int s) {
	memset(dis, 63, sizeof dis);
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (q.size()) {
		int u = q.front();
		vis[u] = 0;
		q.pop();
		for (auto tmp: E[u]) {
			int v = tmp.first, w = tmp.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] > n) {
					return 0;
				}
				if (!vis[v]) vis[v] = 1, q.push(v);
			}	
		}
	}
	return 1;
}

main() {
	cin >> n >> m;
	rep(i, 1, m) {
		int typ, a, b, c;
		cin >> typ >> a >> b;
		if (typ == 1) {
			int c;
			cin >> c;
			E[a].push_back({b, -c});
		} if (typ == 2) {
			int c;
			cin >> c;
			E[b].push_back({a, c});
		} if (typ == 3) {
			E[a].push_back({b, 0});
			E[b].push_back({a, 0});
		}
	}
	rep(i ,1, n) E[0].push_back({i, 0});
	if (!spfa(0)) {
		rtn
	} else rty
//	int t; cin >> t; while (t--) solve();
	return 0;
}
