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

int n, m;
const int N = 5005, M = 2E5 + 5;
struct edge {
  int u, v, w, next;
}E[M];
int tot, head[N], fa[N];
void add(int u, int v, int w) {
  E[++tot] = {u, v, w, head[u]};
  head[u] = tot;
}

bool cmp(edge a, edge b) {
  return a.w < b.w;
}

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
  }
  rep(i, 1, n) {
    fa[i] = i;
  }
  sort(E + 1, E + tot + 1, cmp);
  int cnt = 0;
  int res = 0;
  rep(i, 1, tot) {
    int fau = E[i].u, fav = E[i].v;
    fau = find(fau); fav = find(fav);
    if (fau != fav) {
      cnt++;
      res += E[i].w;
      fa[fau] = fav;
    }
    if (cnt + 1 == n) {
      cout << res;
      return 0;
    }
  }
  cout << "orz";
	return 0;
}
