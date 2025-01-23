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

int n, K;
int _m[1005][1005];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> K;
  while (n--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    x1++, y1++; x2++, y2++;
    _m[x2][y2]++, _m[x1][y1]++, _m[x1][y2]--, _m[x2][y1]--;
  }
  int ans = 0;
  rep(i, 1, 1001) {
    rep(j, 1, 1001) { 
      _m[i][j] += _m[i - 1][j] + _m[i][j - 1] - _m[i - 1][j - 1];
      //cout << _m[i][j] << " ";
      ans += _m[i][j] == K;
    }
    //cout << "\n";
  }
  cout << ans;
	return 0;
}
