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
const int N = 1e3  + 5;
int n, fa[N], dp[N];
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 2, n) {
    cin >> fa[i];
    int x = i;
    while (x) {
      x = fa[x];
      dp[x]++;
    }
  }
  rep(i, 1, n) {
    cout << dp[i] + 1 << endl;
  }
	return 0;
}
