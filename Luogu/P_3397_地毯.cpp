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

int n, m, arr[1005][1005];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  while (m--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    arr[x1][y1]++; arr[x2 + 1][y1]--, arr[x1][y2 + 1]--, arr[x2 + 1][y2 + 1]++;
  }
  rep(i, 1, n) rep(j, 1, n) arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
  rep(i, 1, n) { rep(j, 1, n) cout << arr[i][j] << " "; cout << "\n"; }
	return 0;
}
