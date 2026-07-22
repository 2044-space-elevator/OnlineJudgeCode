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
const int N = 1E5 + 5;
const int MAXM = (1 << 20) +  5;
int dp[MAXM], num[N], sum[N][25], n, m;


main() {
	cin >> n >> m;
	rep(i, 1, n) {
		int x;
		cin >> x;
		num[x]++;
		rep(j, 1, m) {
			sum[i][j] = sum[i - 1][j];
		}
		sum[i][x]++;
	}
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	repq(i, 0, 1 << m) {
		int len = 0;
		repq(j, 0, m) {
			if (i & (1 << (j))) len += num[j + 1];
		} 
		rep(j, 1, m) {
			if (i & (1 << (j - 1))) {
				dp[i] = min(dp[i], dp[i ^ (1 << (j - 1))] + num[j] - sum[len][j] + sum[len - num[j]][j]);
			}
		}	
	}
	cout << dp[(1 << m) - 1];
//	int t; cin >> t; while (t--) solve();
	return 0;
}
