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


main() {
//	int t; cin >> t; while (t--) solve();
  int x, k;
  cin >> x >> k;
  int sum = 0;
  sum += x / 1000 % 10 % k * 1000;
  sum += x / 100 % 10 % k * 100;
  sum += x / 10 % 10 % k * 10;
  sum += x % 10 % k;
  cout << sum;
	return 0;
}
