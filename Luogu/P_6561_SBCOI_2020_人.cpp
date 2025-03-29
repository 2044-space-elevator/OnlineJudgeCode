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
const int mod = 998244353;
int fac[(int)1e6 + 1], inv[(int)1e6 + 1];
const int N = 1e6;

int quickpow(int a, int b) {
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

void init() {
  fac[0] = 1;
  inv[0] = 1;
  rep(i, 1, N) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= mod;
    inv[i] = quickpow(fac[i], mod - 2);
  }
}

void solve() {
  int m, a, b;
  cin >> m >> a >> b;
  int c1 = fac[m - b] * inv[a] % mod * inv[m - b - a] % mod;
  int c2 = fac[m - a] * inv[b] % mod * inv[m - a - b] % mod;
  cout << c1 * c2 % mod << endl;
}


main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  init();
	int t; cin >> t; while (t--) solve();
	return 0;
}
