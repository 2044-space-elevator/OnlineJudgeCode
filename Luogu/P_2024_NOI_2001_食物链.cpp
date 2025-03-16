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

int fa[(int)2e5];
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    fa[fx] = fy;
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m;
  cin >> n >> m;
  rep(i, 1, 3 * n) fa[i] = i;

  int ans = 0;
  while (m--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (x > n || y > n) {
      ans++;
      continue;
    }
    if (op == 1) {
      int fx = find(x), fy = find(y + n), 
      ffy = find(y + 2 * n);
      if (fx == fy || fx == ffy) ans++;
      else {
        merge(x, y);
        merge(x + n, y + n);
        merge(x + 2 * n, y + 2 * n);
      }
    } if (op == 2) {
      int fx = find(x), fy = find(y);
      if (x == y || fx == fy || find(x + 2 * n) == fy) {
        ans++;
        continue;
      }
      merge(x, y + 2 * n);
      merge(x + n, y);
      merge(x + 2 * n, y + n);
    }
  }
  cout << ans;
	return 0;
}
