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
ll dp[105][4003];
ll sum[105], dp2[105][2005], arr[105][2005];
const int mod = 998244353;


main() {
//	int t; cin >> t; while (t--) solve();
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> arr[i][j];
            sum[i] += arr[i][j];
            sum[i] %= mod;
        }
    } 
    dp2[0][0] = 1;
    rep(i, 1, n) rep(j, 0, i) {
        dp2[i][j] = dp2[i - 1][j];
        if (j) dp2[i][j] += dp2[i - 1][j - 1] * sum[i] % mod;
        dp2[i][j] %= mod;
    }
    int Ans = 0;
    rep(j, 1, n) Ans += dp2[n][j], Ans %= mod;
    int Ans2 = 0;
    rep(t, 1, m) {
        memset(dp, 0, sizeof dp);
        dp[0][n] = 1;
        rep(i, 1, n) {
            rep(j, n - i, i + n) {
                dp[i][j] = dp[i - 1][j];
                dp[i][j] += dp[i - 1][j - 1] * arr[i][t] % mod;
                dp[i][j] %= mod;
                dp[i][j] += dp[i - 1][j + 1] * (sum[i] - arr[i][t]) % mod;
                dp[i][j] %= mod;
            }
            rep(j, n + 1, 2 * n ) {
                Ans2 += dp[n][j];
                Ans2 %= mod;
            }
        }
    }
    cout << (Ans - Ans2 + mod) % mod;
	return 0;
}
