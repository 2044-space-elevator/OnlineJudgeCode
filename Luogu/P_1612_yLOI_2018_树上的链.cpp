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
#define int ll
const int N = 1e5 + 5;
vct<int> E[N];
int w[N], c[N], ans[N], fa[N], dp[N], cnt;
int n;

void dfs(int x, int last) {
  fa[++cnt] = x;
  dp[x] = dp[last] + w[x];
  int left = 1, right = cnt;
  while (left < right) {
    int mid = (left + right) >> 1;
    if (dp[x] - dp[fa[mid - 1]] <= c[x]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  ans[x] = max(ans[x], cnt - right + 1);
  for (int v : E[x]) {
    dfs(v, x);
  }
  cnt--;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 2, n) {
    int x;
    cin >> x;
    E[x].push_back(i);
  }
  rep(i, 1, n) {
    ans[i] = 1;
    cin >> w[i];
  }
  rep(i, 1, n) {
    cin >> c[i];
  }
  dfs(1, 0);
  rep(i, 1, n) {
    cout << ans[i] << ' ';
  }
	return 0;
}
