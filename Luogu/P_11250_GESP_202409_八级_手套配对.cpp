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

const int mod = 1e9 + 7;
const int N = 1e5;
ll fac[N], inv[N];

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

main() {
    fac[0] = inv[0] = 1;
    repq(i, 1, N){
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
    //cout << inv[4] << endl;
	int t; cin >> t;
     while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        if (n - k < m - 2 * k || k > n || m - 2 * k < 0) {
            cout << 0 << endl;
            continue;
        }
        ll ans = C(k, n) % mod * C(m - 2 * k, n - k) % mod * qpow(2, m - 2 * k)  % mod; 
        cout << ans << endl;
    }
	return 0;
}
