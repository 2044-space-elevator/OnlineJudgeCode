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

int _m[10][10];

main() {
  //  int t; cin >> t; while (t--) solve();
  rep(i, 1, 9) rep(j, 1, 9) {
    cin >> _m[i][j];
  }
  rep(i, 1, 9) {
    rep(j, 1, 9) {
      rep(k, 1, 9) {
        if (k != j && _m[i][j] == _m[i][k] || k != i && _m[i][j] == _m[k][j]) {
          cout << "Invalid" << endl;
          return 0;
        }
        int gzi = (i - 1) / 3, gzj = (j - 1) / 3;
        rep(k, 1, 3) {
          rep(l, 1, 3) {
            int x = gzi * 3 + k, y = gzj * 3 + l;
            if (x == i && y == j) continue;
            if (_m[i][j] == _m[x][y]) {
              cout << "Invalid" << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "Valid" << endl;
  return 0;
}