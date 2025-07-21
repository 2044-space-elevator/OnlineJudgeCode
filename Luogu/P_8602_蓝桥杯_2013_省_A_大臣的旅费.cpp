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

#define int ll

const int N = 1e5 + 5;
vct<pair<int, int> > E[N];
int d[N], c, mx = 0;

void dfs(int u, int fa) {
    for (auto tmp : E[u]) {
        int v = tmp.first, w = tmp.second;
        if (v == fa) continue;
        d[v] = d[u] + w;
        if (d[v] > mx) {
            c = v;
            mx = d[v];
        }
        dfs(v, u);
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    repq(i, 1, n) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    dfs(1, 0);
    mx = 0, d[c] = 0;
    dfs(c, 0);
    cout << (10ll * d[c] + d[c] * (d[c] + 1ll) / 2ll);
	return 0;
}
