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

#define int ll
const int MOD = 998244353;
const int N = 2e5 + 5;
int n, arr[N];
ll qpow(ll base, ll exp) {
    ll ans = 1;
    while (exp) {
        if (exp & 1) ans *= base;
        ans %= MOD;
        exp >>= 1;
        base *= base;
        base %= MOD;
    }
    return ans;
}
void solve() {
    cin >> n;
    rep(i, 1, n) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    ll ans = 0;
    rep(i, 1, n) {
        ans = ans + qpow(2, n - i) * (qpow(3, i - 1) + 1) % MOD * arr[i] % MOD * qpow(2, MOD - 2) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
