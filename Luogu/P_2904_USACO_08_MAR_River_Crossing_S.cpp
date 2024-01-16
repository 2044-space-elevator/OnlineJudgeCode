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

const int N = 2505;
int dp[N], M[N], n, sum[N], m;

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> M[i]; 
        sum[i] = sum[i - 1] + M[i];
    }
    rep(i, 1, n) {
        sum[i] += 2 * m;
    }
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    rep(i, 1, n) {
        rep(j, i, n) {
            dp[j] = min(dp[j - i] + sum[i], dp[j]);
        }
    }
    cout << dp[n] - m;
	return 0;
}
