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
const int N = 5e5 + 5;
vector<int> tree[N];
int dep[N];
int fa[N][20];

void dfs(int s, int fat) {
  for (int v : tree[s]) {
    if (v == fat) {
      continue;
    }
    dep[v] = dep[s] + 1;
    fa[v][0] = s;
    rep(j, 1, log2(dep[v])) {
      fa[v][j] = fa[fa[v][j - 1]][j - 1];
    }
    dfs(v, s);
  }
}

int LCA(int x, int y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  while (dep[x] > dep[y]) {
    int d = log2(dep[x] - dep[y]);
    x = fa[x][d];
  }
  if (x == y) {
    return y;
  }
  rrep(j, 0, log2(dep[x])) {
    if (fa[x][j] != fa[y][j]) {
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  return fa[x][0];
}

int k[105];
main() {
//	int t; cin >> t; while (t--) solve();
  int n, m, s;
  cin >> n >> m >> s;
  repq(i, 1, n) {
    int x, y;
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  dfs(s, s);
  while (m--) {
    int x, y;
    cin >> x >> y;
    cout << LCA(x, y) << endl;
  }
}