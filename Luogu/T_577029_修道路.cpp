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

#define int ll
int n, m, s;
int fa[(int)1e6 + 5];
bool p[(int)1e6 + 5];
struct node {
  int u, v, w;
};
vct<node> E;

int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}

void insert(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  fa[x] = y;
}

bool cmp(node a, node b) {
  return a.w < b.w;
}



main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m >> s;
  rep(i, 1, n) {
    fa[i] = i;
  }
  rep(i, 1, m) {
    int u, v, w;
    cin >> u >> v >> w;
    E.push_back({u, v, w});
    E.push_back({u, v, w});
  }
  sort(E.begin(), E.end(), cmp);
  int cnt = 0;
  int sum = 0;
  for (auto [u, v, w] : E) {
    if (find(u) != find(v)) {
      insert(u, v);
      cnt++;
      sum += w;
    }
    if (cnt == n -1) break;
  }
  while (s--) {
    int a;
    cin >> a >> a >> a; 
    sum += a;
  }
  cout << sum;
	return 0;
}
