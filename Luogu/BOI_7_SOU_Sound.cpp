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

int arr[(int)1e6 + 10], STMax[(int)1e6 + 10][32], STMin[(int)1e6 + 10][32];
int n, m, c;

int query (int l, int r) {
  int k = (int)log2(r - l + 1);
  int Mx = max(STMax[l][k], STMax[r - (1 << k) + 1][k]);
  int Mn = min(STMin[l][k], STMin[r - (1 << k) + 1][k]);
  return Mx - Mn;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> c;
  rep(i, 1, n) { cin >> arr[i]; STMax[i][0] = STMin[i][0] = arr[i]; }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n - (1 << j) + 1; i++) {
      STMax[i][j] = max(STMax[i][j - 1], STMax[i + (1 << j - 1)][j - 1]);
      STMin[i][j] = min(STMin[i][j - 1], STMin[i + (1 << j - 1)][j - 1]);
    }
  }
  bool flg = 1;
  rep(i, 1, n - m + 1) {
    if (query(i, i + m - 1) <= c) { cout << i << endl; flg = 0; }
  }
  cout << (flg ? "NONE" : "");
	return 0;
}
