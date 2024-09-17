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

const int N = 505;

int cnt, f[N];

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);

}

struct edge {
  int u, v, w;
}E[N * N];

void add(int u, int v, int w) {
  E[++cnt] = {u, v, w};
}

bool cmp(edge a, edge b) {
  return a.w < b.w;
}

main() {
//	int t; cin >> t; while (t--) solve();
  int k, n;
  cin >> k >> n;
  rep(i, 1, n) {
    f[i] = i;
    add(0, i, k);
  }
  rep(i, 1, n) {
    rep(j, 1, n) {
      int x;
      cin >> x;
      if (!x) continue;
      add(i, j, x);
    }
  }
  sort(E + 1, E + cnt + 1, cmp);
  int ans = 0;
  rep(i, 1, cnt) {
    int u = E[i].u, v = E[i].v;
    int fu = find(u), fv = find(v);
    if (fu == fv) {
      continue;
    }
    f[fv] = fu;
    ans += E[i].w;
  }
  cout << ans;
	return 0;
}
