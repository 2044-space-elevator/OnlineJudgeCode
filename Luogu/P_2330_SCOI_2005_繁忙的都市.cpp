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

const int N = 305, M = 8e3 + 5;

int n, m, fa[N];
struct node {
  int u, v, w;
};

vct<node> E;

bool cmp(node a, node b) { return a.w < b.w; }

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) fa[i] = i;
  int tmp = 0;
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    tmp += w;
    E.push_back({u, v, w});
  }
  sort(E.begin(), E.end(), cmp);
  int cnt = 0, ans = 0;
  while (cnt < n - 1) {
    for (auto e : E) {
      int u = find(e.u), v = find(e.v);
      if (u != v) {
        fa[u] = v;
        ans = max(ans, e.w);
        cnt++;
      }
    }
  }
  cout << n - 1 << ' ' << ans; 
	return 0;
}
