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

int n, k;
const int N = 2e5 + 5;
int dep[N], fa[N][31];
int nearest_door[N];
vct<int> G[N];

void dfs(int u, int fat) {
    dep[u] = dep[fat] + 1;
    fa[u][0] = fat;
    repq(i, 1, 31) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int v : G[u]) {
        if (v == fat) continue;
        dfs(v, u);
    }
}

int  lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    rrep(i, 0, 30) {
        if (dep[x] <= dep[fa[y][i]]) {
            y = fa[y][i];
        }
    }
    if (x == y) return x;
    rrep(i, 0, 30) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    x = fa[x][0];
    return x;
}

int dist(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

main() {
//	int t; cin >> t; while (t--) solve();
    fill(nearest_door + 1, nearest_door + N, -1);
    int q;
    cin >> n >> k >> q;
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> que;
    rep(i, 1, k) {
        int x;
        cin >> x;
        nearest_door[x] = 0;
        que.push(x);
    }
    while (que.size()) {
        int x = que.front();
        que.pop();
        for (int v : G[x]) {
            if (nearest_door[v] != -1) continue;
            nearest_door[v] = nearest_door[x] + 1;
            que.push(v);
        }
    }
    //dep[1] = 1;
    dfs(1, 0);
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans2 = dist(x, y);
        if (nearest_door[x] == -1 || nearest_door[y] == -1) {
            cout << ans2 << endl; 
            continue;
        }
        cout << min(ans2, nearest_door[x]+ nearest_door[y]) << endl;
    }
	return 0;
}
