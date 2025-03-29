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
const int mod = 1e9 + 7;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		a %= mod;
		res %= mod;
		b >>= 1;
	}
	return res;

}

const int MAXN = 1e6 + 5;
int inv[MAXN], D[MAXN], fac[MAXN];

void init() {
	fac[0] = 1;
	D[2] = 1;
	rep(i, 3, 1e6) {
		D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % mod;
	}
	rep(i, 1, 1e6) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
		inv[i] = qpow(fac[i], mod - 2);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	if (n == m) cout << 1 << endl;
	else if (n - m == 1) cout << 0 << endl;
	else if (m == 0) cout << D[n] << endl;
	else 
	cout << fac[n] * inv[m] % mod * inv[n - m] % mod * D[n - m] % mod << endl;	
}
main() {
	init();
	int t; cin >> t; while (t--) solve();
	return 0;
}
