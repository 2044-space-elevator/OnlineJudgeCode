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
int n, W, weight[105], value[105], dp[550][550];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> W;
    int minv = LONG_LONG_MAX;
    int sum = 0;
    rep(i, 1, n) {
        cin >> weight[i] >> value[i];
        minv = min(minv, weight[i]);
    }
    rep(i, 1, n) {
        weight[i] -= (minv - 1);
        sum += weight[i];
    }
    minv--;
    rep(i, 1, n) {
        rrep(j, weight[i], sum) {
            rrep(k, 1, n) {
                if (j + k * (minv) > W) {
                    continue;
                }
                dp[j][k] = max(dp[j][k], dp[j - weight[i]][k - 1] + value[i]);
            }
        }
    }
    int ans = 0;
    rep(i,1, sum) {
        rep(j, 1, n) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
	return 0;
}
