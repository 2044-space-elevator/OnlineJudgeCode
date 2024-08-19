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

int qzh[105][105];

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m, k;
  cin >> n >> m >> k;
  rep(i, 1, n) {
    rep(j, 1, m) {
      char ch;
      cin >> ch;
      qzh[i][j] = qzh[i][j - 1] + qzh[i - 1][j] - qzh[i - 1][j - 1] + (ch == '1');
    }
  }
  int sum = INT_MAX;
  rep(zx, 1, n) {
    rep(zy, 1, m) {
      rep(yx, zx, n) {
        rep(yy, zy, m) {
          int ans = qzh[yx][yy] - qzh[yx][zy - 1] - qzh[zx - 1][yy] + qzh[zx - 1][zy - 1];
          if (ans >= k) sum = min(sum, (yx - zx + 1) * (yy - zy + 1));
        } 
      }
    }
  }
  cout << (sum == INT_MAX ? 0 : sum);
	return 0;
}
