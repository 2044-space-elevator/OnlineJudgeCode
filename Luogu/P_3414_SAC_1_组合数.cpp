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

#define int ll

const int mod = 6662333;
int n;

int qpow(int base, int k) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= base;
      res %= mod;
    }
    base *= base;
    base %= mod;
    k >>= 1;
  } return res;
}

main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n;
  cout << (qpow(2, n - 1));
  return 0;
}