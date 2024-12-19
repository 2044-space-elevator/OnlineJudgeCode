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
#define INF 1e15
const int N = 1E6 + 5;
struct SegmentTree {
  int l, r, val, lazadd, lazfix = INF;
} tree[4 * N];
int arr[N];

void pushUp(int x) {
  tree[x].val = max(tree[x * 2].val, tree[x * 2 + 1].val);
}

void pushDown(int x) {
  if (tree[x].lazfix != INF) {
    tree[x << 1].val = tree[x].lazfix;
    tree[x << 1 | 1].val = tree[x].lazfix;
    tree[x << 1].lazfix = tree[x].lazfix;
    tree[x << 1 | 1].lazfix = tree[x].lazfix;
    tree[x].lazfix = INF;

  }
  if (tree[x].lazadd) {
    tree[x << 1].val += tree[x].lazadd;
    tree[x << 1 | 1].val += tree[x].lazadd;
    tree[x << 1].lazadd += tree[x].lazadd;
    tree[x << 1 | 1].lazadd += tree[x].lazadd;
    tree[x].lazadd = 0;
  }
}

void build(int x, int l, int r) {
  tree[x].l = l, tree[x].r = r, tree[x].lazadd = 0, tree[x].lazfix = INF;
  if (l == r) {
    tree[x].val = arr[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
  pushUp(x);
}

void updateAdd(int x, int l, int r, int v) {
  if (l <= tree[x].l && r >= tree[x].r) {
    tree[x].val += v;
    tree[x].lazadd += v;
    return;
  }
  pushDown(x);
  int mid = (tree[x].l + tree[x].r) >> 1;
  if (l <= mid) updateAdd(x * 2, l, r, v);
  if (r > mid) updateAdd(x * 2 + 1,
                         l, r, v);
  pushUp(x);
}

void updateFix(int x, int l, int r, int v) {
  if (l <= tree[x].l && r >= tree[x].r) {
    tree[x].val = v;
    tree[x].lazfix = v;
    tree[x].lazadd = 0;
    return ;
  }
  pushDown(x);
  int mid = (tree[x].l + tree[x].r) >> 1;
  if (l <= mid) updateFix(x * 2, l, r, v);
  if (r > mid) updateFix(x * 2 + 1, l, r, v);
  pushUp(x);
}

int query(int x, int l, int r) {
  if (l <= tree[x].l && r >= tree[x].r) return tree[x].val;
  pushDown(x);
  int mid = (tree[x].l + tree[x].r) >> 1, ans = -1e15;
  if (l <= mid) ans = max(ans, query(x * 2, l, r));
  if (r > mid) ans = max(ans, query(x * 2 + 1, l, r));
  return ans;
 }
main() {
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) {
    cin >> arr[i];
  }
  build(1, 1, n);
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      updateFix(1, l, r, v);
    } else if (op == 2) {
      int l, r, v;
      cin >> l >> r >> v;
      updateAdd(1, l, r, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(1, l, r) << '\n';
    }
  }
//	int t; cin >> t; while (t--) solve();
	return 0;
}
