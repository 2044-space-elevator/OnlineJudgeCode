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
const int N = 1e7 + 5;

int weight[N], value[N], dp[N];

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> value[i] >> weight[i];
    }
    int ret = 1e18;
    rep(i, 1, m + 5000) {
        dp[i] = ret;
    }
    rep(i, 1, n) {
        rep(j, value[i], m + 5000) {
            dp[j] = min(dp[j], dp[j - value[i]] + weight[i]);
        }
    }
    rep(i, m, m + 5000) {
        ret = min(ret, dp[i]);
    }
    cout << ret ;
	return 0;
}
