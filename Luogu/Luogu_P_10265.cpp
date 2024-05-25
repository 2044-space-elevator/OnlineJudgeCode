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

const int N = 1005, M = 1005;
int n, m;
bool g[N][N], res[N];
vct<int> ans;

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) {
    rep(j, 1, n) {
      cin >> g[i][j];
      if (i == j) g[i][j] = 1;
    }
  } 
  int a1 = 0, a2 = 0;
  rep(i, 1, n) {
    if (g[i][m]) a1++;
    if (g[m][i]) a2++;
  }
  cout << a2 << ' ' << a1 << ' ' << a1 + a2;
	return 0;
}
