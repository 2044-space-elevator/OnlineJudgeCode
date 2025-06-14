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
const int N = 1005, mod = 1e9 + 7;

ll fac[N], inv[N];
ll arr[N], now[N];

ll qpow(ll a, ll ex) {
    ll ans = 1;
    while (ex) {
        if (ex & 1) ans *= a;
        ans %= mod;
        a *= a;
        a %= mod;
        ex >>= 1;
    }
    return ans;
}

ll C(ll m, ll n) {
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
void solve() {
    ll n, m;
    cin >> n >> m;
    int sum = 0;
    rep(i, 1, m) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum == n) {
        ll ans = 1, tmp = n;
        rep(i, 1, m) {
            ans *= C(arr[i], tmp); ans %= mod;
            tmp -= arr[i];
        }
        cout << ans << endl;
    } else {
        ll ans = 0;
        rep(j, 1, m) {
            ll tmp = 1; 
            ll ttn = n;
            rep(i, 1, m) {
                tmp *= C(arr[i] - (i == j), ttn);
                tmp %= mod;
                ttn -= (arr[i] - (i == j));
            }
            ans += tmp;
            ans %= mod;
        }
        cout << ans << endl;
    }
}


main() {
    fac[0] = inv[0] = 1;
    repq(i, 1, N) {
        fac[i] = fac[i - 1] * i; fac[i] %= mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
	int t; cin >> t; while (t--) solve();
	return 0;
}
