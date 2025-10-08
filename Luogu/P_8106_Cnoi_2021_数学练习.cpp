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

const ll mod = 998244353;
#define int ll
const int N = 1E5 + 5;
int fac[N], inv[N];

ll qpow(ll base, ll exp) {
    ll ans = 1;
    while (exp) {
        if (exp & 1) ans *= base;
        ans %= mod;
        exp >>= 1;
        base *= base;
        base %= mod;
    }
    return ans;
}

ll C(ll m, ll n) {
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}


main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    ll ans = 0;
    if (n <= 2) {
        cout << 0;
        return 0;
    }
    fac[0] = 1;
    rep(i, 1, n) {
        fac[i] = i * fac[i - 1];
        fac[i] %= mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
    ans = qpow(2, n - 2);
    if (n % 2 == 0) {
        ans -= C(n / 2 - 1, n - 2);
        ans += mod;
        ans %= mod;
    }
    cout << ans;
	return 0;
}
