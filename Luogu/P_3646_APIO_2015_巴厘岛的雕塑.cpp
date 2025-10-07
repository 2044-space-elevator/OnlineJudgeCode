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
const int N = 2005;
bool dp[N][N];
int arr[N], sum[N], n, a, b, g[N];

ll solve1() {
    int maxn = log2(sum[n]) + 1;
    ll ans = 0;
    rrep(pos, 0, maxn) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        ll ret = ans | ((1ll << pos) - 1ll);
        rep(i, 1, n) {
            rep(j, 1, min(i, b)) {
                repq(k, j - 1, i) {
                    if ((ret | (sum[i] - sum[k])) == ret && dp[k][j - 1]) {
                        dp[i][j] = 1;
                        goto __;
                    }
                }
                __:;
            }
        }
        rep(i, a, b) {
            if (dp[n][i]) {
               goto _; 
            }
        }
        ans = ans | (1ll << pos);
        _:;
    }
    return ans;
}

ll solve2() {
    int maxn = log2(sum[n]) + 1;
    ll ans = 0;
    rrep(pos, 0, maxn) {
        int ret = ans | ((1ll << pos) - 1ll);
        memset(g, 127, sizeof g);
        g[0] = 0;
        rep(i, 1, n) {
            repq(k, 0, i) {
                if (((sum[i] - sum[k]) | ret) == ret) {
                    g[i] = min(g[i], g[k] + 1);
                }
            }
        }
        if (g[n] > b) {
            ans = ans | (1ll << pos);
        }
    }
    return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> a >> b;
    rep(i, 1, n) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    if (a == 1) cout << solve2();
    else cout << solve1();
	return 0;
}
