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
int n, cnt, head[N];
struct edge {
  int u, v, next;
}E[N];

void add(int u, int v) {
  E[++cnt] = {u, v, head[u]};
  head[u] = cnt;
}

int ans = 2147483647;

int dfs(int u, int fa) {
  int sum = 1, res = 0;
  for (int i = head[u]; i; i = E[i].next) {
    if (E[i].v != fa) {
      int t = dfs(E[i].v, u);
      sum += t;
      res = max(res, t);
    }
  }
  res = max(res, n - sum);
  ans = min(ans, res);
  return sum;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) {
    int x, y;
    cin >> x >> y;
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  cout << ans;
	return 0;
}
