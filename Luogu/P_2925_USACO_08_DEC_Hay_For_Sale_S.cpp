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

int weight[(int)5e3 + 5], dp[(int)5e4 + 5];
main() {
//	int t; cin >> t; while (t--) solve();
    int T, n;
    cin >> T >> n;
    rep(i, 1, n) {
        cin >> weight[i];
    }
    rep(i, 1, n) {
        rrep(j, weight[i], T) {
            dp[j] = max(dp[j], dp[j - weight[i]] + weight[i]);
        }
    }
    cout << dp[T];
	return 0;
}
