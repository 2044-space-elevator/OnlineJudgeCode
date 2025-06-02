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

int dp[11][16];
int val[11][16];
int path[11][16][16];

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> val[i][j];
    rep(i, 1, n) {
        rrep(j, 0, m) {
            rep(k, 0, j)
            if (dp[i][j] <= dp[i - 1][j - k] + val[i][k]) {
                dp[i][j] = dp[i - 1][j - k] + val[i][k];
                repq(h, 1, i)
                    path[i][j][h] = path[i - 1][j - k][h];
                path[i][j][i] = k;
            }
        }
    }
    cout << dp[n][m] << endl;
    rep(i, 1, n) cout << i << ' ' << path[n][m][i] << '\n';
	return 0;
}
