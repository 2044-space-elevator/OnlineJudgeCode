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

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0; return ;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

ll ksc(ll a, ll b, ll mod) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans += a;
        b >>= 1;
        a += a;
        ans %= mod;
    }
    return ans;
}

main() {
    ll sa, sb, n, m, L;
    cin >> sa >> sb >> m >> n >> L;
    ll a = n - m, b = sa - sb;
    if (a < 0) a = -a, b = -b;
    while (b < 0) {
        b += L;
    }
    b %= L;
    // ax + Ly = b
    ll d = __gcd(a, L);
    if (b % d) {
        cout << "Impossible";
        return 0;
    }
    L /= d, a /= d, b /= d;
    ll x,  y;
    exgcd(a, L, x, y);
    while (x < 0) x += L; x %= L;
    cout << ksc(x, b, L);;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
