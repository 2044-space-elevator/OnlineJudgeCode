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

const int N = 1005;
int n, m;
int col[N][N], row[N][N], l[N][N], r[N][N];
int L[N][N], R[N][N];
char _m[N][N];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) {
    cin >> _m[i][j];
    if (_m[i][j] == 'F') col[i][j] = col[i -  1][j] + 1;
  }
  rep(i, 1, n) {
    int t = 0;
    rep(j, 1, m) {
      if (_m[i][j] == 'F') 
        l[i][j] = t;
      else L[i][j] = 0, t = j;
    }
    t = m + 1;
    rrep(j, 1, m) {
      if (_m[i][j] == 'F') 
        r[i][j] = t;
      else R[i][j] = m + 1, t = j;
      R[0][j] = m + 1;
    }
  }
  int ans = 0;
  rep(i, 1, n) rep(j, 1, m) {
    if (_m[i][j] == 'F') {
      L[i][j] = max(L[i - 1][j], l[i][j] + 1);
      R[i][j] = min(R[i - 1][j], r[i][j] - 1);
      int ll = L[i][j], rr = R[i][j];
      ans = max(ans, (rr - ll + 1) * col[i][j]);
    }
  }
  cout << ans * 3;
	return 0;
}
