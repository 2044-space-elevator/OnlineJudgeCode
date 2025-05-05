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
int k;
int arr[15], brr[15];
ll prodm = 1;

int qpow(int base, int ex, int mod) {
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

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) x = 1, y = 0;
    else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

ll gsc(ll base, ll ex, ll mod) {
    ll ans = 0;
    while (ex) {
        if (ex & 1) ans += base;
        ans %= mod;
        base += base;
        base %= mod;
        ex >>= 1;
    }
    return ans;
}
main() {
//	int t; cin >> t; while (t--) solve();
    cin >> k;
    rep(i, 1, k) cin >> arr[i];
    rep(i, 1, k) { cin >> brr[i]; prodm *= brr[i]; }
    rep(i, 1, k) {
        arr[i] = ((arr[i] % prodm + prodm) % prodm + prodm) % prodm;
    }
    int ans = 0;
    ll x, y;
    rep(i, 1, k) {
        exgcd(prodm / brr[i], brr[i], x, y);
        x = (x % prodm + prodm) % prodm;
        ans += gsc(gsc(prodm / brr[i], x, prodm), arr[i], prodm);
        ans %= prodm;
    }
    cout << ans;
	return 0;
}
