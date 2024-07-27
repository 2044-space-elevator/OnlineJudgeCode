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
  stg s;
  int ret1 = 0, ret2 = 0;
  cin >> s;
  for (char v : s) {
    if (v == '(') {
      ret1++;
    } else {
      if (ret1) ret1--;
      else ret1++, ret2++;
    }
  }
  cout << ret2 + ret1 / 2;
	return 0;
}
