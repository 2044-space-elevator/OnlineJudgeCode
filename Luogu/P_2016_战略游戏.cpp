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

int n, dp[1505][2];
vct<int> E[1505];

void dfs(int u, int fa) {
    dp[u][1] = 1;
    for (int v : E[u]) {
        if (fa == v) continue;
        dfs(v, u);
        dp[u][1] += min({dp[v][0], dp[v][1]});
        dp[u][0] += dp[v][1];
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    rep(i, 1, n) {
        int u;
        cin >> u;
        ++u;
        int q;
        cin >> q;
        while (q--) {
            int v;
            cin >> v;
            ++v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
    }
    int ans = 1505;
    rep(root, 1, n) {
        memset(dp, 0, sizeof dp);
        dfs(root, 0);
        ans = min({ans, dp[root][0], dp[root][1]});
    }
    cout << ans << ' ';
	return 0;
}
