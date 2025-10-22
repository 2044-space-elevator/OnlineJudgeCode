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

ll mod = 1e9 + 7;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        ans %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    cout << (ll)((qpow(2, n) - 1ll + mod) % mod);
	return 0;
}
