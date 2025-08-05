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
const int N = 505;
int d[N], dp[N][N], f[N][N];

main() {
//	int t; cin >> t; while (t--) solve();
    int n, k;
    cin >> n >> k;
    memset(dp, 63, sizeof dp);
    rep(i ,2, n) cin >> d[i];
    rep(i, 2, n) d[i] += d[i - 1];
    rep(i, 1, n) {
        rep(j, i, n) {
            int mid = (i + j) / 2;
            rep(k, i, j)
                f[i][j] += abs(d[mid] - d[k]); 
            if (i == 1)
                dp[j][1] = f[1][j];
        }
    }
    rep(i, 1, n) {
        rep(j, 2, min(n, k)) {
            repq(l, 1, i) {
                dp[i][j] = min(dp[i][j], dp[l][j - 1] + f[l + 1][i]);
            }
        }
    }
    cout << dp[n][k];
	return 0;
}
