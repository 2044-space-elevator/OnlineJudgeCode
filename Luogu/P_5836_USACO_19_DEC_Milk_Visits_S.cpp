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

bool is_in_h[(int)1e5 + 5][32], is_in_g[(int)1e5 + 5][32];
int n, m;
bool typ[(int)1e5 + 5];
const int N = 1E5 + 5;
int fa[N][32], dep[N];
vct<int> E[N];

void dfs(int u, int fat) {
    dep[u] = dep[fat] + 1;
    fa[u][0] = fat;
    if (!typ[u]) {
        is_in_g[u][0] = 1; 
    } else {
        is_in_h[u][0] = 1;
    }
    is_in_g[u][0] |= (!typ[fa[u][0]]);
    is_in_h[u][0] |= (typ[fa[u][0]]);
    rep(i, 1, 31) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        is_in_h[u][i] = is_in_h[u][i - 1] | is_in_h[fa[u][i - 1]][i - 1];
        is_in_g[u][i] = is_in_g[u][i - 1] | is_in_g[fa[u][i - 1]][i - 1];
    }
    for (int v : E[u]) {
        if (v == fat) continue;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) {
        swap(x, y);
    }
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

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m;
    cin >> n >> m;
    stg s;
    cin >> s;
    repq(i, 0, s.size()) {
        if (s[i] == 'H') {
            typ[i + 1] = 1;
        }
    }
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    while (m--) {
        int u, v;
        char ty;
        cin >> u >> v >> ty;
        int lc = lca(u, v);
        if (ty == 'G') {
            bool cz = !typ[u] || !typ[v];
            rrep(i, 0, 31) {
                if (dep[fa[u][i]] >= dep[lc]) {
                    cz |= is_in_g[u][i];
                    u = fa[u][i];
                }
            }
            rrep(i, 0, 31) {
                if (dep[fa[v][i]] >= dep[lc]) {
                    cz |= is_in_g[v][i];
                    v = fa[v][i];
                }
            }
            cout << cz;
        } else {
            bool cz = typ[u] || typ[v];
            rrep(i, 0, 31) {
                if (dep[fa[u][i]] >= dep[lc]) {
                    cz |= is_in_h[u][i];
                    u = fa[u][i];
                }
            }
            rrep(i, 0, 31) {
                if (dep[fa[v][i]] >= dep[lc]) {
                    cz |= is_in_h[v][i];
                    v = fa[v][i];
                }
            }
            cout << cz;
        }
    }
	return 0;
}
