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
  int n;
  cin >> n;
  repq(i, 1, n) {
    int x;
    cin >> x;
    tree[x].push_back(i);
    tree[i].push_back(x);
  }
  dfs(0, 0);
  int q;
  cin >> q;
  while (q--) {
    int m, a, b;
    cin >> m >> a;
    rep(i, 2, m) {
      cin >> b;
      a = LCA(a, b);
    }
    int maxn = a;
    while (a) {
      maxn = max(maxn, fa[a][0]);
      a = fa[a][0];
    }
    cout << maxn << endl;
  }
	return 0;
}
