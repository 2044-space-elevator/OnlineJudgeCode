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

ll dp[105][105][105];
int n, m;
vct<int> status;
char s[105][15];

int mount[105];

main() {
	cin >> n >> m;
	rep(i, 1, n) {
		rep(j, 1, m) {
			cin >> s[i][j];
			if (s[i][j] == 'H') mount[i] |= (1 << (j - 1));
		}
		
	}
	repq(i, 0, (1 << m)) {
		if (i & (i << 1) || i & (i << 2)) continue;
		status.push_back(i);
	}
	memset(dp, -1, sizeof dp);
	int sz = status.size() - 1;
	rep(j, 0, sz) {
		if (status[j] & mount[1]) continue;
		dp[1][j][0] = __builtin_popcount(status[j]);
	}
	rep(i, 2, n) {
		rep(j, 0, sz) {
			int S = status[j];
			if (S & mount[i]) continue;
			rep(k, 0, sz) {
				int S1 = status[k];
				if (S1 & mount[i - 1]) continue;
				if (S & S1) continue;
				rep(l, 0, sz) {
					int S2 = status[l];
					if (S2 & mount[i - 2]) continue;
					if (S & S2 || S1 & S2) continue;
					if (dp[i - 1][k][l] < 0) continue;
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l] + __builtin_popcount(status[j]));
				}
			}
		}
	}
	ll ans = 0;
	rep(i, 0, sz) {
		rep(j, 0, sz) ans = max(ans, dp[n][i][j]);
	}
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
