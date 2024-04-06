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
  int mymoney = 0, dif, sum = 0, ma = 0;
  rep(i, 1, n) {
    int a, c;
    cin >> a >> c;
    dif = c - mymoney;
    if (dif <= 0) {
      mymoney = abs(dif);
      continue;
    } 
    ma = max(ma, a);
    mymoney = 0;
    sum += ceil(dif / ma);
    if (dif % ma) {
      mymoney += dif % ma;
      sum++;
    }
  }
  cout << sum;
  return 0;
}