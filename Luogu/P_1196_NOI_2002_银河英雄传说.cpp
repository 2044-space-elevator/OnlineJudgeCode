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
const int N = 3e4 + 5;
int fa[N], siz[N], dep[N];
int find(int x) {
  if (x == fa[x]) return x;
  int fx = find(fa[x]);
  dep[x] += dep[fa[x]];
  return fa[x] = fx;

}

void solve() {
  char op;int  x, y;
  cin >> op >> x >> y;
  int fx = find(x), fy = find(y);
  if (op == 'M') {
    fa[fx] = fy;
    dep[fx] += siz[fy];
    siz[fy] += siz[fx];
    siz[fx] = 0;
  } else {
    if (fx == fy) {
      cout << abs(dep[y] - dep[x]) - 1<< endl;
    } else cout << -1 << endl;
  }
}


main() {
  rep(i, 1, 3e4) fa[i] = i, siz[i] = 1, dep[i] = 0;;
	int t; cin >> t; while (t--) solve();
	return 0;
}
