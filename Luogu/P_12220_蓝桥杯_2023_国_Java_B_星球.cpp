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
double x[20], y[20], z[20], w[20], dp[1 << 19][20];

double dis(int inda, int indb) {
    return sqrt((x[inda] - x[indb]) * (x[inda] - x[indb]) + (y[inda] - y[indb]) *
        (y[inda] - y[indb]) + (z[inda] - z[indb]) * (z[inda] - z[indb]));
}

main() {
//	int t; cin >> t; while (t--) solve();
    memset(dp, 127, sizeof dp);
    cin >> n;
    rep(i,1, n) { 
        cin >> x[i] >> y[i] >> z[i] >> w[i]; 
        dp[1 << i - 1][i] = 0;
    }
    repq(i, 0, 1 << n) {
        rep(j, 1, n) {
            if (i & (1 << j - 1)) {
                rep(k, 1, n) {
                    if (i & (1 << k - 1)) {
                        dp[i][j] = min(
                            dp[i][j],
                            dp[i ^ (1 << j - 1)][k] + dis(j, k) * w[j]
                        ) ;
                    }
                } 
            }
        }
    }
    double ans = 1e18;
    rep(i, 1, n) ans = min(ans, dp[(1 << n) - 1][i]);
    printf("%.2lf", ans);
	return 0;
}
