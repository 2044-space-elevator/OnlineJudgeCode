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

const int N = 1E3 + 5, Q = 2E3 + 5;
bool active[N], edge_use[Q];
pair<int, int> edges[Q];

struct question {
	char typ;
	int a, b, bcnt;
};
question que[Q];

int fa[N], edge_cnt, ans[N];

int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]); 
}

main() {
//	int t; cin >> t; while (t--) solve();
	int n, q;
	cin >> n >> q;
	rep(i, 1, n) {
		fa[i] = i;
	}
	rep(i, 1, q) {
		char typ;
		cin >> typ;
		if (typ == 'A') {
			int u, v;
			cin >> u >> v;
			edge_use[++edge_cnt] = 1;
			edges[edge_cnt] = {u, v};
			que[i] = {typ, u, v, edge_cnt};
		}
		if (typ == 'R') {
			int ecnt;
			cin >> ecnt;
			edge_use[ecnt] = 0;
			que[i].typ = typ, que[i].a = ecnt;		
		}
		if (typ == 'D') {
			int rem;
			cin >> rem;
			active[rem] = 0;
			que[i].typ = typ, que[i].a = rem;
		}
	}
	rep(i, 1, edge_cnt) {
		if (!edge_use[i]) {
			continue;
		}
		int u = edges[i].first, v = edges[i].second;
		int fu = find(edges[i].first), fv = find(edges[i].second);
		active[fu] |= active[fv];
		active[fv] |= active[fu];
		active[u] |= (active[v] | active[fv] | active[fu]);
		active[v] |= (active[u] | active[fu] | active[fv]);
		fa[fu] = fv;
	}
	rep(i, 1, n) {
		if (active[i]) {
			cout << i << ' ';
		}
	}
	return 0;
}
