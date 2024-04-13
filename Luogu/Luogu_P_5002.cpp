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
const int MAXN = 1e4 + 5;

struct edge {
  int u, v, next;
}E[MAXN * 10];
int head[MAXN], dep[MAXN], ans[MAXN], cnt;

void add(int u, int v) {
  E[++cnt] = {u, v, head[u]};
  head[u] = cnt;
}

void dfs(int u, int f) {
  dep[u] = 1;
  for (int i = head[u]; i; i = E[i].next) {
    int v = E[i].v;
    if (v == f) {
      continue;
    }
    dfs(v, u);
    ans[u] += dep[u] * dep[v] * 2;
    dep[u] += dep[v];
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  int n, r, m;
  cin >> n >> r >> m;
  repq(i, 1, n) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  dfs(r, r);
  while (m--) {
    int x;
    cin >> x;
    cout << ans[x] + 1<< endl;
  }
	return 0;
}
