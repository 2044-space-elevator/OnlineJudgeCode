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
  int n;
  cin >> n;
  int cnt = 0, res = 0, cnt2 = 0, res2 = 0;
  rep(i, 1, n) {
    int x; 
    cin >> x;
    if (x) cnt++;
    else {
      cnt = 0;
    } 
    res = max(res, cnt);
  }
  while (n--) {
    int x;
    cin >> x;
    if (x) cnt2++;
    else {
      cnt2 = 0;
    }
    res2 = max(res2, cnt2);
  }
  if (res < res2) cout << "Bella\n";
  else if (res == res2) cout << "Draw\n";
  else cout << "Bob\n";
}


main() {
  int t; cin >> t; while (t--) solve();
  return 0;
}