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

const int N = 3E5 + 5;
int order[N], fa[N][32], dep[N], cf[N];
vct<int> E[N];
void dfs(int u, int fat) {
    dep[u] = dep[fat] + 1;
    fa[u][0] = fat;
    rep(i, 1, 31) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : E[u]) {
        if (v == fat) continue;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    rrep(i, 0, 31) {
        if (dep[fa[y][i]] >= dep[x]) {
            y = fa[y][i];
        }
    }
    if (x == y) return x;
    rrep(i, 0, 31) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

void sum(int u, int fat) {
    for (int v : E[u]) {
        if (v == fat) continue;
        sum(v, u);
        cf[u] += cf[v];
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    rep(i, 1, n) cin >> order[i];
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    rep(i, 2, n) {
        int from = order[i - 1], to = order[i];
        int lc = lca(from, to);
        cf[from]++, cf[to]++, cf[lc]--, cf[fa[lc][0]]--;
    }
    sum(1, 0);
    // cf[order[1]]++, cf[order[n]]--;
    rep(i, 2, n) {
        cf[order[i]]--;
    }
    rep(i, 1, n) {
        cout << cf[i] << '\n';
    }
	return 0;
}
