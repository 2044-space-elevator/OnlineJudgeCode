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
  
}


main() {
  //  int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  int nowspeed = 1;
  int maxest = 0;
  int lastx = 0;
  rep(i, 1, n) {
    int x, L;
    cin >> x >> L;
    int k = ceil((double)(L + x - lastx - 1 - nowspeed) / 2);
    k = min(k, x - lastx - 1);
    maxest = max(maxest, nowspeed + k);
    nowspeed = min(nowspeed + x - lastx - 1, L);
    lastx = x;
  }
  cout << maxest;
  return 0;
}