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
int n, m, in[N], in_rec[N];
double dis[N];
vct<pair<int, int> > E[N];

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		E[v].push_back({u, w});
		in[u]++; in_rec[u]++;
	}
	queue<int> q;
	q.push(n);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto tmp : E[u]) {
			int v = tmp.first, w = tmp.second;
			dis[v] += (dis[u] + w) / in_rec[v];
			if (!--in[v]) {
				q.push(v);
			}
		}
	}
	printf("%.2lf", dis[1]);
	return 0;
}
