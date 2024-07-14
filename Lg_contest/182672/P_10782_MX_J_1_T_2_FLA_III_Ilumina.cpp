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
  int a, c;
  cin >> a >> c;
  int left = 1, right = a;
  while (left <= right) {
    int midn = (left + right) >> 1;
    int b = a / midn;
    if (b == c) {
      cout << b << endl;
      return;
    }
    if (b > c) {
      left = midn + 1;
    }
    else {
      right = midn - 1;
    }
  }
  cout << "-1\n";
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
