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

const int N = 1e4 + 5;
int scccnt, belonged[N], n, m, low[N], dfn[N], cnt, fa[N][32], dep[N];
bool in[N], flg[N], nT[N][N];
vct<int> E[N], neT[N];
stack<int> st;

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++cnt;
    st.push(u);
    int child = 0;
    in[u] = 1;
    for (int v : E[u]) {
        if (v == fa) continue;
        if (!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (v != fa && !belonged[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        scccnt++;
        int j = -1;
        while (j != u) {
            j = st.top(); st.pop();
            belonged[j] = scccnt;
            in[j] = 0;
        }
    }
}

void dfs(int u, int fat) {
    flg[u] = 1;
    fa[u][0] = fat;
    dep[u] = dep[fat] + 1;
    repq(i, 1, 32) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : neT[u]) {
        if (v == fat || flg[v]) continue;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    rrep(i, 0, 31) {
        if (dep[fa[x][i]] >= dep[y]) {
            x = fa[x][i];
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
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    rep(i, 1, n) if (!dfn[i]) tarjan(i, 0);
    rep(u, 1, n) {
        for (int v : E[u]) {
            if (belonged[u] == belonged[v]) continue;
            neT[belonged[u]].push_back(belonged[v]);
            neT[belonged[v]].push_back(belonged[u]);
        }   
    }
    memset(flg, 0, sizeof flg);
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int dis = 1 +  dep[belonged[u]] + dep[belonged[v]] - 2 * dep[lca(belonged[u], belonged[v])];
        stg ans = "";
        while (dis) {
            if (dis % 2) ans += '1';
            else ans += '0';
            dis /= 2;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
	return 0;
}
