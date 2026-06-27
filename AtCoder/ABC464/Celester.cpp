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

const int N = 2E5 + 5;
ll dp[N][2];
int x[N], y[N];
stg s;
void solve() {
	int n;
	cin >> n;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = -2e14;
	rep(i, 1, n) cin >> x[i];
	rep(i, 2, n) cin >> y[i];
	if (s[1] == 'S') {
		dp[1][1] = -x[1]; dp[1][0] = 0;
	} else dp[1][0] = -x[1], dp[1][1] = 0;
	rep(i, 2, n) {
		if (s[i] == 'S') {
			dp[i][0] = max(
				dp[i - 1][0],
				dp[i - 1][1] + y[i]
			);
			dp[i][1] = max(
				dp[i - 1][0],
				dp[i - 1][1]
			) - x[i];
		} else {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + y[i]) - x[i];
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	cout << max(dp[n][0], dp[n][1]) << '\n';
}


main() {
	int t;cin >> t; 
	while (t--) solve();
	return 0;
}
