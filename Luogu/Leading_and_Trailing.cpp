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

ll fastpow(ll a, ll b, ll p) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res % p;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  ll last = fastpow(n, k, 1000);
  double re = (double)k * log10((double)n);
  double tmp = pow(10.0, 2 + re - (int)(re));
  cout << (int)tmp << "...";
  if (last < 10) cout << '0';
  if (last < 100) cout << '0';
  cout << last << endl;
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
