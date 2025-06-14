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

int n;
bool flg[(int)1e5 + 5];
vct<int> E[(int)1e5 + 5];
vct<int> fz[(int)1e5 + 5];
int dp[(int)1e5 + 5];

void dfs(int u, int fa) {
    dp[u] = 1;
    for (int v : E[u]) {
        if (v == fa) continue;
        fz[u].push_back(v);
        dfs(v, u);
        if (flg[u] != flg[v]) {
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n;
    rep(i ,1, n) {
        cin >> flg[i];
    }
    repq(i, 1, n) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 1;
    rep(i, 1, n) {
        ans = max(ans, dp[i]) ;
        repq(s, 0, fz[i].size()) {
            repq(t, s + 1, fz[i].size()) {
                int fs = fz[i][s], sc = fz[i][t];
                if (flg[fs] == flg[sc] && flg[sc] != flg[i]) {
                    ans = max(ans, dp[fs] + dp[sc] + 1);
                }
            }
        }
    }
    cout << ans;
	return 0;
}
