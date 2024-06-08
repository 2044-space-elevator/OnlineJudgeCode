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

void solve() {
  int m, n, c;
  cin >> m >> n >> c;
  swap(m, n);
  int _g = __gcd(m, n);
  m /= _g, n /= _g;
  int d = max(ceil((double)c / m), ceil((double)c / n));
  cout << d * (m + n) << endl; 
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
