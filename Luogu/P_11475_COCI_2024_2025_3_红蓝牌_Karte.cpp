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

int ans = 0;
bool flg[26][26];
int per[26];
bool chose[26];
int n, m, X, Y;
void solve() {
	
}
int count(int x) {
  int cnt = 0;
  while (x) {
    cnt += x & 1;
    x %= 2;
  }
  return cnt;
}


main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> X >> Y;
  rep(i, 1, n) {
    rep(j, 1, m) {
      char c;
      cin >> c;
      flg[i][j] = (c == '1');
    }
  } 
  repq(s, 0, (1 << n)) {
    int red = __builtin_popcount(s);
    int sum = -red * X;
    rep(j, 1, m) {
      int cnt = 0;
      repq(i, 0, n) {
        if ((s >> i) & 1) {
          cnt += flg[i + 1][j];
        }
      }
      if (cnt > Y) sum += cnt - Y;
    }
    ans = max(ans, sum);
  }
  cout << ans;
	return 0;
}
