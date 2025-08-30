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

const int N = 1E4 + 5;
vct<int> tree[1][N];
vct<pair<int, int> > tree_gen[10][N];
int belonged[N], tree_cnt, belonged_count[10], belonged_rt[10];
struct edge {
	int u, v, w;
};
vct<edge> E;
vct<edge> E_divided[10];
int n, m, q;

void query_belonged(int u) {
	belonged_rt[tree_cnt] = u;
	belonged_count[tree_cnt]++;
	belonged[u] = tree_cnt;
	for (int v : tree[0][u]) {
		if (!belonged[v]) {
			query_belonged(v);
		}
	}
}

bool cmp(edge a, edge b) {
	return a.w > b.w;
}

int fa[10][N][32], dep[10][N], minn[10][N][32];

int find(int u) {
	return u == fa[0][u][0] ? fa[0][u][0] : fa[0][u][0] = find(fa[0][u][0]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	fa[0][fx][0] = fy;
}

void dfs(int u, int fat, int typ) {
	fa[typ][u][0] = fat;
	dep[typ][u] = dep[typ][fat] + 1;
	rep(i, 1, 31) {
		fa[typ][u][i] = fa[typ][fa[typ][u][i - 1]][i - 1];
	}
	rep(i, 1, 31) {
		minn[typ][u][i] = min(minn[typ][u][i - 1], minn[typ][fa[typ][u][i - 1]][i - 1]);
	}
	for (auto tmp : tree_gen[typ][u]) {
		int v = tmp.first;
		if (v == fat) continue;
		minn[typ][v][0] = tmp.second;
		dfs(v, u, typ);
	}
}

int lca(int x, int y, int typ) {
	if (dep[typ][x] > dep[typ][y]) swap(x, y);
	rrep(i, 0, 31) {
		if (dep[typ][fa[typ][y][i]] >= dep[typ][x]) {
			y = fa[typ][y][i];
		}
	}
	if (x == y) {
		return x;
	}
	rrep(i, 0, 31) {
		if (fa[typ][x][i] != fa[typ][y][i]) {
			x = fa[typ][x][i], y = fa[typ][y][i];
		}	
	}
	return fa[typ][x][0];
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({u, v, w});
		E.push_back({v, u, w});
		tree[0][u].push_back(v);
		tree[0][v].push_back(u);
	}	
	rep(i, 1, n) {
		if (!belonged[i]) {
			tree_cnt++;
			query_belonged(i);
		}
	}
	for (edge tmp : E) {
		int u = tmp.u, v = tmp.v, w = tmp.w;
		E_divided[belonged[u]].push_back(tmp);
	}
	rep(i, 1, tree_cnt) {
		sort(E_divided[i].begin(), E_divided[i].end(), cmp);
	}
	rep(i, 1, tree_cnt) {
		int edge_count = 0;
		rep(j, 1, n) {
			fa[0][j][0] = j;
		}
		for (edge tmp : E_divided[i]) {
			int u = tmp.u, v = tmp.v, w = tmp.w;
			if (edge_count == belonged_count[i]) {
				break;
			}
			if (find(u) == find(v)) {
				continue;
			}
			merge(u, v);
			tree_gen[i][u].push_back({v, w});
			tree_gen[i][v].push_back({u, w});
		}
	}
	rep(i, 1, tree_cnt) {
		dfs(belonged_rt[i], 0, i);
	}
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (belonged[x] != belonged[y]) {
			cout << "-1\n";
			continue;
		}
		int lc = lca(x, y, belonged[x]);
		int ans = 1e9, typ = belonged[x];
		rrep(i, 0, 31) {
			if (dep[typ][fa[typ][x][i]] >= dep[typ][lc]) {
				ans = min(ans, minn[typ][x][i]);
				x = fa[typ][x][i];
			}
		}
		rrep(i, 0, 31) {
			if (dep[typ][fa[typ][y][i]] >= dep[typ][lc]) {
				ans = min(ans, minn[typ][y][i]);
				y = fa[typ][y][i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
