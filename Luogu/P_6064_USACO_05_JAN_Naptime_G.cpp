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
int n, b;
int dp[3885][3835][2], w[3835];


main() {
	cin >> n >> b;
	rep(i, 1, n) cin >> w[i];
	memset(dp, -63, sizeof dp);
	dp[1][0][0] = dp[1][1][1] = 0;
	rep(i, 2, n) {
		dp[i][0][0] = dp[i - 1][0][0];
		rep(j, 1, b) {
			dp[i][j][0] = max(dp[i - 1][j][1], dp[i - 1][j][0]);
			dp[i][j][1] = max(dp[i - 1][j - 1][1] + w[i], dp[i - 1][j - 1][0]);
		}	
	}
	int ans = max(dp[n][b][1], dp[n][b][0]);
	memset(dp, -63, sizeof dp);
	dp[1][0][0] = 0;
	dp[1][1][1] = w[1];
	rep(i, 2, n) {
		dp[i][0][0] = dp[i - 1][0][0];
		rep(j, 1, b) {
			dp[i][j][0] = max(dp[i - 1][j][1], dp[i - 1][j][0]);
			dp[i][j][1] = max(dp[i - 1][j - 1][1] + w[i], dp[i - 1][j - 1][0]);
		}	
	}
	ans = max(ans, dp[n][b][1]);
	cout << ans << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
