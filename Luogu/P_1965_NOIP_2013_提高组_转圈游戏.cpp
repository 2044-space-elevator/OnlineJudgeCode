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

int rounds[(int)1e6 + 5];
int fpow(int ds, int ex, int m) {
    int bs = 1;
    while (ex) {
        if (ex &1) {
            bs *= ds;
            bs %= m;
        }
        ds *= ds;
        ds %= m;
        ex >>= 1;
    }
    return bs;
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    // freopen("C:\\Users\\S.X.Y\\Desktop\\t.out", "w", stdout);
    // repq(i,/ 0, n) {
        // x += m;
        // x %= n;
        // rounds[i] = x;
        // cout << rounds[i] << ' ';
    // }
    int ans = m;
    ans *= fpow(10, k, n);
    ans %= n;
    ans += x;
    ans %= n;
    cout << ans;
	return 0;
}
