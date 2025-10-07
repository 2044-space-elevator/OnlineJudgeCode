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

ll dp[55][55][2], pos[55], arr[55], sum[55];

main() {
//	int t; cin >> t; while (t--) solve();
    int n, st;
    cin >> n >> st;
    rep(i, 1, n) {
        cin >> pos[i] >> arr[i];
        sum[i] = arr[i] + sum[i - 1];
    }
    // dp[l][r][0/1]
    // dp[l][r][0] = min(dp[l + 1][r][0] + (aj - ai) (sum - sum[l + 1][r]), dp[l + 1][r] + 
    //    )
    memset(dp, 127, sizeof dp);
    dp[st][st][0] = dp[st][st][1] = 0;
    rep(len, 2, n) {
        rep(l, 1, n) {
            int r = l + len - 1;
            dp[l][r][0] = min(dp[l + 1][r][0] + (pos[l + 1] - pos[l]) * (sum[n] - (sum[r] - sum[l])), dp[l + 1][r][1] + (pos[r] - pos[l]) * (sum[n] - (sum[r] - sum[l])));
            dp[l][r][1] = min(dp[l][r - 1][1] + (pos[r] - pos[r - 1]) * (sum[n] - (sum[r - 1] - sum[l - 1])), dp[l][r - 1][0] + (pos[r] - pos[l]) * (sum[n] - sum[r - 1] + sum[l - 1]));
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]);
	return 0;
}
