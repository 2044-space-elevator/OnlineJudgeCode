#include <bits/stdc++.h>
#define rty printf("Yes\n");
#define RTY printf("YES\n");
#define rtn printf("No\n");
#define RTN printf("NO\n");
#define rep(v,b,e) for(ll v=b;v<=e;v++)
#define repq(v,b,e) for(ll v=b;v<e;v++)
#define rrep(v,e,b) for(ll v=b;v>=e;v--)
#define rrepq(v,e,b) for(ll v=b;v>e;v--)
#define stg string
#define vct vector
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define int ll
void solve() {
  ll a, b, r;
  cin >> a >> b >> r;
  if (a < b) {
    swap(a, b);
  }
  ll res = 0, cnt = 0;
  rrep(i, 0, 60) {
    ll atmp = a & (1ll << i), btmp = b & (1ll << i);
    if (atmp == btmp) {
      continue;
    }  
    if (!cnt) {
      cnt++;
    } 
    else if (atmp && ((res + (1ll << i)) <= r)) {
      a ^= (1ll << i), b ^= (1ll << i);
      res += (1ll << i);
    }
  }
  cout << abs(a - b) << endl;
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
