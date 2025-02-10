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
int fa[(int)2e5 + 5];
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) fa[fx] = fy;

}


main() {
//	int t; cin >> t; while (t--) solve();
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) fa[i] = i;
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      merge(x, y);
    } else {
      int x, y;
      cin >> x >> y;
      if (find(x) == find(y)) cout << "Y\n";
      else cout << "N\n";
    } 
  }

	return 0;
}
