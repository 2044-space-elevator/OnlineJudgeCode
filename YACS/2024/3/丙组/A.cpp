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
  ll n, d;
  cin >> n >> d;
  int num1 = (int)(n / d) * d, num2 = ceil((double)n / d) * d;
  int dif = min(abs(num1 - n), abs(num2 - n));
  if (abs(num1 - n) == dif) {
    cout << num1 << endl;
  }
  if (num1 == num2) return 0;
  if (abs(num2 - n) == dif) {
    cout << num2 << endl;
  }
  return 0;
}