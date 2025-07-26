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

const int N = 5e4 + 5;
vct<int> E[N];
int dc[N];
int dep[N];
int fa[N][20];

void dfs(int u, int fat) {
    fa[u][0] = fat, dep[u] = dep[fat] + 1;
    for (int j = 1; j <= 19; j++) {
        fa[u][j] = fa[fa[u][j - 1]][j - 1];
    } 
    for (int v : E[u]) {
        if (v == fat) {
            continue;
        }
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) {
        swap(x, y);
    }
    while (dep[x] > dep[y]) {
        int d = log2(dep[x] - dep[y]);
        x = fa[x][d];
    }
    if (x == y) return y;
    rrep(j, 0, 19) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j], y = fa[y][j];
        }
    }
    return fa[x][0];
}

void jh(int u, int fa) {
    for (int v : E[u]) {
        if (v == fa) {
            continue;
        }
        jh(v, u);
        dc[u] += dc[v];
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n, q;
    cin >> n >> q;
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dep[u] > dep[v]) swap(u, v);
        int lc = lca(u, v);
        dc[fa[lc][0]]--;
        dc[lc]--;
        dc[u]++;
        dc[v]++;
    }
    jh(1, 0);
    int ans = 0;
    rep(i, 1, n) {
        ans = max(ans, dc[i]);
    } 
    cout << ans;
	return 0;
}
