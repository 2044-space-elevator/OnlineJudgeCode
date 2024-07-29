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

int arr[105][105];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m, k;
  cin >> n >> m >> k;
  rep(i, 1, m) {
    int x, y;
    cin >> x >> y;
    arr[x][y] = 1;
  }
  rep(x, 1, n) {
    rep(y, 1, n) {
      arr[x][y] += arr[x - 1][y] + arr[x][y - 1] - arr[x - 1][y - 1];
    }
  }
  int res = 0;
  rep(xa, 1, n) {
    rep(ya, 1, n) {
      rep(xb, xa, n) {
        rep(yb, ya, n) {
          int ans = arr[xb][yb] - arr[xa - 1][yb] - arr[xb][ya - 1] + arr[xa - 1][ya - 1];
          res += ans >= k;
        }
      }
    }
  }
  cout << res;
	return 0;
}
