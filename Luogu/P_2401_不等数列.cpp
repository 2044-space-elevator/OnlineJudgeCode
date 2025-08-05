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
const int N = 1005;
int dp[N][N];

main() {

    int n, k;
    cin >> n >> k;
    rep(i, 1, n) {
        dp[i][0] = 1;
        rep(j, 1, min(n - 1, k)) {
            dp[i][j] = dp[i - 1][j] * (j + 1) + (dp[i - 1][j - 1]) * (i - j); 
            dp[i][j] %= 2015;
        }
    }
    cout << dp[n][k];
//	int t; cin >> t; while (t--) solve();
	return 0;
}
