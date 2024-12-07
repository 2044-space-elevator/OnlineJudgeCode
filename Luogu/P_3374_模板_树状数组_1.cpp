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
const int N = 5E5 + 5;

int arr[4 * N];
struct SegmentTree {
  int l, r, dat;
}t[4 * N];

void build(int p, int l, int r) {
  t[p].l = l; t[p].r = r;
  if (l == r) {
    t[p].dat = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  t[p].dat = t[p * 2].dat + t[p * 2 + 1].dat;
}

void change(int p, int x, int v) {
  if (t[p].l == t[p].r) {
    t[p].dat += v;
    return;
  }
  int mid = (t[p].l + t[p].r) / 2;
  if (x <= mid) change(p * 2, x, v);
  else change(p * 2 + 1, x, v);
  t[p].dat = t[p * 2].dat + t[p * 2 + 1].dat;
}

int query(int p, int l, int r) {
  if (l <= t[p].l && t[p].r <= r) return t[p].dat;
  int mid = (t[p].l + t[p].r) / 2, ans = 0;
  if (mid >= l) ans += query(p * 2, l, r);
  if (mid < r) ans += query(p * 2 + 1, l, r);
  return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
  int n, m; cin >> n >> m;
  rep(i, 1, n) { cin >> arr[i]; }
  build(1, 1, n);
  while (m--) {
    int op, l, r; cin >> op >> l >> r;
    if (op == 1) change(1, l, r);
    else cout << query(1, l, r) << endl;
  }
	return 0;
}
