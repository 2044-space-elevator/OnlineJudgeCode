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

const int N = 105;
bitset<N> dis[N];

main() {
  //  int t; cin >> t; while (t--) solve();
  int n, x;
  cin >> n;
  rep(i, 1, n) {
    rep(j, 1, n) {
      cin >> x;
      dis[i][j] = x;
    }
  }
  rep(k, 1, n) {
    rep(i, 1, n) {
      rep(j, 1, n) {
        if (dis[i][k]) {
          dis[i] |= dis[k];
        }
      }
    }
  }
  rep(i, 1, n) {
    rep(j ,1, n) {
      cout << dis[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}