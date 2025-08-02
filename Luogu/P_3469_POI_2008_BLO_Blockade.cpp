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
vct<int> E[N];
int dfn[N], low[N], cnt, n;
ll ans[N], siz[N];

void dfs(int u) {
    siz[u] = 1;
    dfn[u] = low[u] = ++cnt;
    ll sum = 0;
    int cn = 0;
    bool flg = 0;
    for (int v : E[u]) {
        if (!dfn[v]) {
            dfs(v);
            siz[u] += siz[v];
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                ans[u] += siz[v] * ((ll)n - siz[v]); 
                sum += siz[v];
                cn++;
                if (u != 1 || cn > 1) flg = 1;
            }
        } else low[u] = min(low[u], dfn[v]);
    }
    if (!flg) ans[u] = 2 * n - 2;
    else ans[u] += (ll)(n - sum - 1) * (sum + 1) + (n - 1);
}


main() {
//	int t; cin >> t; while (t--) solve();
int m;
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1);
    rep(i, 1, n) cout << ans[i] << endl;
	return 0;
}
