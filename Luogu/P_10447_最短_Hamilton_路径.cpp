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
int dp[(1 << 20)][25];
int arr[25][25];

main() {
	cin >> n;
	repq(i, 0, n) {
		repq(j, 0, n) cin >> arr[i][j];
	}
	memset(dp, 63, sizeof dp);
	dp[1][0] = 0;
	repq(S, 1, (1 << n)) {
		repq(i, 0, n) {
			if (!(S & (1 << (i)))) {
				continue; 
			}
			repq(j, 0, n) {
				if (!(S & (1 << (j)))) {
					continue;
				}
				if (i == j) continue;
				dp[S][j] = min(dp[S][j], dp[S ^ (1 << j)][i] + arr[i][j]);
			}
		}
	}
	cout << dp[(1 << n) - 1][n - 1];
//	int t; cin >> t; while (t--) solve();
	return 0;
}
