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

int n, m;
bool status[13][13];
int stat[13];
int dp[13][8193];
vct<int> valid[13];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> status[i][j];
            stat[i] += (1 << (j - 1)) * status[i][j];
        }
    }
    rep(i, 1, n) {
        repq(j, 0, 1 << m) {
            if ((j & stat[i]) < j) {
                continue;
            }
            if (j & (j << 1)) continue;
            valid[i].push_back(j);
            if (i == 1) {
                dp[i][j] = 1;
                continue;
            }
            for (int v : valid[i - 1]) {
                if (j & v) continue;
                dp[i][j] += dp[i - 1][v];
                dp[i][j] %= (int)1e8;
            }
        }
    }
    int ans = 0;
    for (int v : valid[n]) {
        ans += dp[n][v];
        ans %= (int)1e8;
    }
    cout << ans;
	return 0;
}
