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
int n;
int fac[(int)1e6 + 5], inv[(int)1e6 + 5];
int per[(int)1e6 + 5];
const int mod = 10007;
bool cmp(int a, int b) {
  if (a % 2 != b % 2)
  return a % 2 > b % 2;
  if (a % 2 == 1)
  return a < b;
  return a > b;
}

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
  rep(i, 1, n) per[i] = i;
  sort(per + 1, per +n  + 1, cmp);
  fac[0] = 1;
  rep(i, 1, 1e6) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= mod;
  }
}

int C(int nn, int mm) {
  if (mm == nn || mm == 0) return 1;
  if (mm > nn) return 0;
  return fac[nn]  * quickpow(fac[mm], mod - 2) % mod * quickpow(fac[nn - mm], mod - 2) % mod;
}

int Lucas(int nn, int mm) {
  if (mm == 0 || nn == mm) return 1;
  if (mm > nn ) return 0;
  return C(nn % mod, mm % mod) * Lucas(nn / mod, mm / mod) % mod;
}
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  init();
  //rep(i, 1, n) cout << per[i] << ' ' ;
  int ans = 0;
  rep(i, 1, n) {
    //cout << ] << ' ';
    //cout << Lucas(n - 1, i - 1) << ' ' ;
    ans += per[i] * Lucas(n - 1, i - 1) % mod;
    ans %= mod;
  }
  cout << ans;
	return 0;
}
