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
const int mod = 100003;
int quickpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    a %= mod;
    b >>= 1; 
    res %= mod;
  }
  return res;
}

main() {
//	int t; cin >> t; while (t--) solve();
  int m, n;
  cin >> m >> n;
  cout << ((quickpow(m, n) - (m * quickpow(m - 1, n - 1)) % mod + 2 * mod) % mod) << endl;
	return 0;
}
