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

ll n;
bool arr[505];
ll c[505], dp[2][505][505][2];

void solve() {
    cin >> n;
    int popc = 0;
    rep(i, 1, n) {
        ll x;
        cin >> x;
        popc += (x % 2);
        arr[i] = x % 2;
    }
    rep(i, 1, n) {
        cin >> c[i];
    }
    memset(dp, 127, sizeof dp);
    dp[1][1][1][1] = c[1] * !arr[1];
    dp[1][0][0][0] = arr[1] * c[1];
    ll INF = dp[0][0][0][0];
    rep(i, 2, n) {
        rep(j, max(0ll, popc + i - n), min(popc, i)) {
            rep(k, 0, i) {
                dp[i & 1][j][k][0] = dp[(i - 1) & 1][j][k][0] + c[i] * arr[i];
                if (j > 0) {
                    dp[i & 1][j][k][0] = min(dp[(i - 1) & 1][j - 1][k][1] + c[i] * !arr[i], dp[i & 1][j][k][0]);
                }
                if (k > 1) {
                    dp[i & 1][j][k][1] = dp[(i - 1) & 1][j][k - 1][1] + c[i] * arr[i];
                    if (j > 1) {
                        dp[i & 1][j][k][1] = min(dp[i & 1][j][k][1], dp[(i - 1) & 1][j - 1][k - 1][0] + !arr[i] * c[i]); 
                    }
                }
            }
        }
    } 
    rep(S, 0, n) {
        ll ans = min(dp[n & 1][popc][S][0], dp[n & 1][popc][S][1]);
        if (ans >= INF) {
            cout << "-1 ";
        } else {
            cout << ans << ' ';
        }
    }
    cout << '\n';
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
