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

const int N = 16005;
int arr[N], dp[N];
vct<int> E[N];

void dfs(int u, int fat) {
    for (int v : E[u]) {
        if (v == fat) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[u] + dp[v]);
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    int ans = -2147483647;
    rep(i, 1, n) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
	return 0;
}
