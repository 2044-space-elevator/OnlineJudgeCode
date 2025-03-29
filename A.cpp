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

int fa[1006][32], dep[1006], black[1006], n, k;
bool stat[1006];
vct<int> E[1005];

void dfs(int u, int last) {
  black[u] += black[last];
  fa[u][0] = last;
  dep[u] = dep[last] + 1;
  repq(i, 1, 31) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  } 
  for (int v : E[u]) {
    if (v == last) continue;
    dfs(v, u);
  }
}

int lca(int x, int y) {
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  while (dep[x] > dep[y]) {
    x = fa[x][(int)log2(dep[x] - dep[y])];
  }
  if (x == y) return x;
  rrep(i, 0, 31) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}

//oid Bubble(int a[10][], int m);
//void Bubble(int a[][], int n, int m);
void Bubble(int (*a)[20], int n);
void Bubble(int * a[20], int n);
main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n >> k;
  rep(i, 1, n) {
    cin >> stat[i];
    black[i] = stat[i];
  }
  repq(i, 1, n) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  dfs(1, 0);
  int ans = 0;
  rep(i, 1, n) {
    rep(j, i + 1, n) {
      int top = lca(i, j);
      int sum = black[i] + black[j] - 2 * black[top] + stat[top];
      if (sum <= k) {
        ans = max(ans, dep[i] + dep[j] - 2 * dep[top] + 1);
      }
    }
  }
  cout << ans;
  return 0;
}