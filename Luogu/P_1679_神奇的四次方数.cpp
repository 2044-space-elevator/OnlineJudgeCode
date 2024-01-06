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

int allscf[(int)1e6 + 5];
int dp[(int)1e6 + 5];


main() {
//	int t; cin >> t; while (t--) solve();
    int m;
    cin >> m;
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    rep(i, 1, 18) {
        allscf[i] = pow(i, 4);
    }
    rep(i, 1, 18) {
        rep(j, allscf[i], m) {
            dp[j] = min(dp[j], dp[j - allscf[i]] + 1);
        }
    }
    cout << dp[m];
    return 0;
}
