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

int n, dp[(int)1e5 + 5], node[(int)1e5 + 5];
vct<int> E[(int)1e5 + 5];

void dfs(int u, int fa) {
    int cnt = 1;
    for (int v : E[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (E[v].size() == 1) {
            cnt++;
        } else dp[u] += dp[v];
    }
    dp[u] += cnt / 2; 
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0); cout << dp[1];
	return 0;
}