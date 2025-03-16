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
const int N = 2E5 + 5;

int Tri[N][2];
int cnt = 0;
int tot = 0;
int endd[N];
struct edge {
  int u, v, w, next;
}E[N];
int head[N], we[N];
void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}
int n;

void dfs(int u, int fa) {
  for (int i = head[u]; i; i = E[i].next) {
    int u = E[i].u, v = E[i].v, w = E[i].w;
    if (v == fa) continue;
    we[v] = we[u] ^ w;
    dfs(v, u);
  }
}

void build(int x) {
  int p = 1;
  rrep(i, 0, 31) {
    int num = (x >> i) & 1;
    if (!Tri[p][num])
      Tri[p][num] = ++tot;
    p = tot;
  } 
  endd[p] = x;
}

int find(int x) {
  int p = 1;
  int ans = 0;
  rrep(i, 0, 31) {
    int f = (x >> i) & 1;
    if (Tri[p][f ^ 1]) {
      ans += (1 << i);
      p = Tri[p][f ^ 1];
    } else p = Tri[p][f];
  }
  return ans; 
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  repq(i, 1, n) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w);
  }
  dfs(1, 0);
  rep(i, 1, n) build(we[i]);
  int ans = 0;
  rep(i, 1, n) ans = max(ans, find(we[i]));
  cout << ans;

	return 0;
}
