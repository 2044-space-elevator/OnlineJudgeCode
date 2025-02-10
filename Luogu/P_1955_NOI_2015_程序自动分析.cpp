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
const int N = 3e6 + 5;
int fa[N];
struct query {
  int type, i, j; 
} qry[N];
int tmp[N * 4];
bool cmp(query a, query b) {
  return a.type > b.type;
}
int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    fa[fx] = fy;
  }
}
void solve() {
  int cnt = 0;
  int n;
  cin >> n;
  rep(l, 1, n) {
    int i, j, type;
    cin >> i >> j >> type;
    qry[l] = {type, i, j};
    tmp[++cnt] = i;
    tmp[++cnt] = j;
  }
  sort(tmp + 1, tmp + cnt + 1);
  cnt = unique(tmp + 1, tmp + cnt + 1) - (tmp + 1);
  rep(l, 1, n) {
    qry[l].i = lower_bound(tmp + 1, tmp + cnt + 1, qry[l].i) - (tmp);
    qry[l].j = lower_bound(tmp + 1, tmp + cnt + 1, qry[l].j) - (tmp);
  }
  rep(i, 1, cnt) fa[i] = i;
  sort(qry + 1, qry + n + 1, cmp);
  rep(l, 1, n) {
    int type = qry[l].type, i = qry[l].i, j = qry[l].j;
    if (type == 1) {
      merge(i, j);
    }
    else {
      if (find(i) == find(j)) {
        RTN;
        return;
      }
    }
  }
  RTY
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
