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

int n, m, weight[1005], value[1005], mapc[1005],
mmapc[1005][1005], dp[1005];

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> m >> n;
	int kk = 0;
	rep(i, 1, n) {
		int k;
		cin >> weight[i] >> value[i] >> k;
		kk = max(kk, k);
		// mapc[k]++;
		mmapc[k][++mapc[k]] = i;
	}
	rep(i, 1, kk) {
		rrep(j, 0, m) {
			rep(k, 1, mapc[i]) {
				int e = mmapc[i][k];
				if (j >= weight[e]) {
					dp[j] = max(dp[j],
					dp[j - weight[e]] + 
					value[e]);
				}
			}
		}
	}
	cout << dp[m];
	return 0;
}
