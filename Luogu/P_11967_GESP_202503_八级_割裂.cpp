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
const int N = 1e6 + 5;

int n, p, dep[N], fa[N][31], cf[N];
vct<int> E[N];
vct<int> son[N];


void init(int u, int fat) {
    dep[u] = dep[fat] + 1;
    fa[u][0] = fat;
    repq(i, 1, 31) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : E[u]) {
        if (v == fat) continue;
        son[u].push_back(v);
        init(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    rrep(i, 0, 30) {
        if (dep[fa[x][i]] >= dep[y]) {
            x = fa[x][i];
        }
    }
    if (x == y) return x;
    rrep(i, 0, 30) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

void dfs(int u, int fa) {
    for (int v : E[u]) {
        if (v == fa) continue;
        dfs(v, u);
        cf[u] += cf[v];
    }
}

bool ans[N];

main() {
    cin >> n >> p;
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    init(1, 0);
    while(p--) {
        int u, v;
        cin >> u >> v;
        cf[u]++, cf[v]++; int tmp = lca(u, v);
        cf[tmp]--;
        if (tmp != 1) cf[fa[tmp][0]]--;
    }
    dfs(1, 0);
    rep(i, 1, n) {
        assert(cf[i] >= 0);
        if (!cf[i]) ans[i] = 1;
    }
    memset(cf, 0, sizeof cf);
    int ff, ss;
    cin >> ff >> ss;
    int tmp = lca(ff, ss);
    cf[ff]++, cf[ss]++, cf[tmp]--;
    if (tmp != 1) cf[fa[tmp][0]]--;
    dfs(1, 0);
    int cnt = 0;
    rep(i, 1, n) {
        if (ans[i] && cf[i]) {
            cnt++; 
        }
    }
    cout << cnt;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
