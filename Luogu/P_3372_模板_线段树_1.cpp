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
const int N = 1E5 + 5;

#define int ll
struct Segment {
  int l, r, data, lazy;
}tree[N * 4];

int arr[N];
void pushUp(int i) {
  tree[i].data = tree[i * 2].data + tree[i * 2 + 1].data;
}
void pushDown(int i) {
  if (tree[i].lazy) {
    int mid = (tree[i].l + tree[i].r) >> 1;
    tree[i * 2].data += tree[i].lazy * (mid - tree[i].l + 1);
    tree[i * 2].lazy += tree[i].lazy;
    tree[i * 2 + 1].data += tree[i].lazy * (tree[i].r - mid);
    tree[i * 2 + 1].lazy += tree[i].lazy;
    tree[i].lazy = 0;
  }
}

void build(int p, int l, int r) {
  tree[p].l = l;
  tree[p].r = r;
  if (l == r) {
    tree[p].data = arr[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  pushUp(p);
}

void update(int p, int l, int r, int k) {
  if (l <= tree[p].l && r >= tree[p].r) {
    tree[p].data += (tree[p].r - tree[p].l + 1) * k;
    tree[p].lazy += k;
    return;
  }
  pushDown(p);
  int mid = (tree[p].l + tree[p].r) >> 1;
  if (l <= mid) update(p * 2, l, r, k);
  if (r > mid) update(p * 2 + 1, l, r, k);
  pushUp(p);
}

int query(int p, int l, int r) {
  if (l <= tree[p].l && r >= tree[p].r) return tree[p].data;
  pushDown(p);
  int sum = 0;
  int mid = (tree[p].l + tree[p].r) >> 1;
  if (l <= mid) sum += query(p * 2, l, r);
  if (r > mid) sum += query(p * 2 + 1, l, r);
  return sum;
}
main() {
//	int t; cin >> t; while (t--) solve();
  int n, m; cin >> n >> m;
  rep(i, 1, n) cin >> arr[i]; build(1, 1, n);
  while (m--) {
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      int k;
      cin >> k;
      update(1, l, r, k);
    } else {
      cout << query(1, l, r) << endl;
    }
  }
	return 0;
}
