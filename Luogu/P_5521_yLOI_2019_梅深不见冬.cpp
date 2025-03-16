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

const int N = 1e5 + 5;
int ans[N], val[N], n;
vct<int> E[N];

bool cmp(int a, int b) {
  return (ans[a] - val[a]) > (ans[b] - val[b]);
}

void dfs(int u) {
  for (int v : E[u]) dfs(v);
  sort(E[u].begin(), E[u].end(), cmp);
  int tmp = 0;
  for (int v : E[u]) {
    if (tmp >= ans[v]) {
      tmp -= val[v];
    } else {
      ans[u] += ans[v] - tmp;
      tmp = ans[v] - val[v];
    }
  }
  ans[u] += max(0, val[u] - tmp);
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 2, n) {
    int fa;
    cin >> fa;
    E[fa].push_back(i);
  }
  rep(i, 1, n) {
    cin >> val[i];
  }
  dfs(1);
  rep(i, 1, n) cout << ans[i] << " ";
	return 0;
}
