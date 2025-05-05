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

const int mod = 19260817;
ll a, b;
int fac[(int)1e5 + 5];

ll qpow(ll base, int ex) {
    ll ans = 1;
    while (ex) {
        if (ex & 1) ans *= base;
        ans %= mod;
        base *= base;
        base %= mod;
        ex >>= 1;
    }
    return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
    stg as, bs;
    cin >> as >> bs;
    int lenb = bs.length();
    int lena = as.length();
    fac[0] = 1;
    repq(i, 1, max(lenb, lena)) {
        fac[i] = fac[i - 1] * 10;
        fac[i] %= mod;
    }
    repq(i, 0, lenb) {
        b += (bs[i] - '0') * (fac[lenb - i - 1]);
        b %= mod;
    }
    repq(i, 0, lena) {
        a += (as[i] - '0') * (fac[lena - i - 1]);
        a %= mod;
    }
    if (b % mod == 0) cout << "Angry!";
    else 
    cout << a * qpow(b, mod - 2) % mod; 
	return 0;
}
