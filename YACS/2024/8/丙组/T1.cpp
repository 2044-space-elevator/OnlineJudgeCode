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
  //  int t; cin >> t; while (t--) solve();
  int ans = 0;
  stg s;
  cin >> s;
  for (char v : s) {
    ans += v == 'Y';
    ans -= v == 'N';
    ans = max(ans, 0);
  }
  cout << ans;
  return 0;
}