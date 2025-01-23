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

const int N = 1e5; 

struct SegmentTree{ int l, r, dat, laz; };

class Tree {
  SegmentTree tree[4 * N + 10];
  void pushUp(int p) {
    tree[p].dat = tree[p * 2].dat + tree[p * 2 + 1].dat;
  }

  int len(int p) { return tree[p].r - tree[p].l + 1;}
  
  void pushDown(int p) {
    if (tree[p].laz) {
      tree[p * 2].dat += tree[p].laz;
      tree[p * 2 + 1].dat += tree[p].laz;
      tree[p * 2].laz += tree[p].laz;
      tree[p * 2 + 1].laz += tree[p].laz;
      tree[p].laz = 0;
    }
  }
  public:
  void build(int p ,int l, int r) {
    tree[p].l = l, tree[p].r = r, tree[p].dat = 0, tree[p].laz = 0;
    if (l == r) {
      return;
    }
    int mid = l + r >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
  }

  void modify(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
      tree[p].dat++;
      tree[p].laz += 1;
      return;
    }
    pushDown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if (l <= mid) modify(p * 2, l, r);
    if (r > mid) modify(p * 2 + 1, l, r);
    pushUp(p);
  }

  int query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) return tree[p].dat;
    pushDown(p);
    int mid = tree[p].l + tree[p].r >> 1, ans = 0;
    if (l <= mid) ans += query(p * 2, l, r);
    if (r > mid) ans += query(p * 2 + 1, l, r);
    return ans;
  }
};
Tree a, b;
main() {
//	int t; cin >> t; while (t--) solve();
	int n, m;
	cin >> n >> m;
  a.build(1, 1, n);
  b.build(1, 1, n);
	while (m--) {
		int op, l, r;
		cin >> op >> l >>r;
    if (op == 1) {
      a.modify(1, l, l);
      b.modify(1, r, r);
    } else {
      cout << a.query(1, 1, r) - b.query(1, 1, l - 1) << endl;
    }
	}
	return 0;
}
