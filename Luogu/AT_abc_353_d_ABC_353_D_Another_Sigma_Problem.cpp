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
const int mod = 998244353;
const int N = 2E5 + 5;
int B[N], S[N], A[N];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        res %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

int f(int x, int y) {
    return (x * qpow(10, log10(y) + 1)) + y;
}

main() {
//	int t; cin >> t; while (t--) solve();
    int n;
    cin >> n;
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) {
        B[i] = B[i - 1] + A[i];
        B[i] %= mod;
        S[i] = S[i - 1] + qpow(10, floor(log10(A[i])) + 1);
        S[i] %= mod;
    }
    ll ans = 0;
    repq(i, 1, n) {
        ans = ans +( A[i] * ((S[n] - S[i] + mod) % mod) % mod + (B[n] - B[i] + mod) % mod )%mod; 
        ans %= mod;
    }

    // repq(i, 1, n) {
    //     rep(j, i + 1, n) {
    //         ans += A[i] * ()pow(10, (ll)((ll)log10(A[j]) + 1))) % mod + A[j];
    //         ans %= mod;
    //     }
    // }
    //cout << log10(10);


    cout << ans;
	return 0;
}
