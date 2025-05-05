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
const int N = 5E6 + 5;
int fac[N], inv[N];
const int mod = 998244353;
int ans = 0;
void solve() {
    int n, m;
    cin >> n >> m;
    int tmp = fac[n] * inv[m] % mod * inv[n - m] % mod;
    tmp %= mod;
    ans ^= tmp;
}

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        res %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;

}

main() {
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    fac[0] = inv[0] =  1;
    rep(i, 1, 5e5) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
        //cout << fac[i] << ' ' << inv[i] << endl;
    }
    inv[(int)5e5] = qpow(fac[(int)5e5], mod - 2);
    rrep(i, 1, N)
	int t, tmp; cin >> t >> tmp; while (t--) solve();
    cout << ans;
	return 0;
}
