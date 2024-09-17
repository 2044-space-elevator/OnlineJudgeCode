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

const int N = 6005;
int siz[N], fa[N], head[N], cnt, ans;

struct edge {
  int u, v, w,  next;
}E[N];


void add(int u, int v, int w) {
  E[++cnt] = {u, v, w, head[u]};
  head[u] = cnt;
}


int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void init()  {
  memset(head, 0, sizeof head);
  rep(i, 1, N) {
    fa[i] = i;
    siz[i] = 1;
  }
  cnt = 0;
  ans = 0;
}

bool cmp(edge a, edge b) {
  return a.w < b.w;
}

void merge(int i) {
  int u = find(E[i].u), v = find(E[i].v), w = E[i].w;
  if (siz[u] < siz[v]) swap(u, v);
  ans += (siz[u] * siz[v] - 1) * (w + 1);
  fa[v] = u;
  siz[u] += siz[v];
}

void solve() {
	init();
  int n;
  cin >> n;
  repq(i, 1, n) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
  }
  sort(E + 1, E + n, cmp);
  repq(i, 1, n) {
    merge(i);
  }
  cout << ans << endl;
}



main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
