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

int n, m;
const int N = 1E6 + 5;
bool A[N], B[N];
ll pow2[N];
const int mod = 998244353;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	pow2[0] = 1;
	ll ans = 0;
	rep(i, 1, n)
		pow2[i] = pow2[i - 1] * 2ll % mod;
	rrep(i, 0, n - 1) {
		char c;
		cin >> c;
		c -= '0'; A[i] = c;
		if (c) ans += pow2[i];
		ans %= mod;
	}
	rrep(i, 0, n - 1) {
		char c;
		cin >> c;
		c -= '0'; B[i] = c;
		if (c) ans += pow2[i];
		ans %= mod;
	}
	rep(i, 1, m) {
		int t, p;
		cin >> t >> p;
		if (t == 1) {
			if (A[p]) ans = (ans - pow2[p] + mod) % mod;
			else ans = (ans + pow2[p]) % mod;
			A[p] = !A[p];
		} else {
			if (B[p]) ans = (ans - pow2[p] + mod) % mod;
			else ans = (ans + pow2[p]) % mod;
			B[p] = !B[p];
		}
		cout << ans << '\n';
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
