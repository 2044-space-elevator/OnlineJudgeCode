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

const int N = 1E6 + 5;
struct ZXTree {
	int l, r, val;
}tree[N * 32];

int cnt, root[N], arr[N];

int build(int l, int r) {
	int rt = ++cnt;
	if (l == r) { tree[rt].val = arr[l]; return rt; } 
	int mid = (l + r) / 2;
	tree[rt].l = build(l, mid);
	tree[rt].r = build(mid + 1, r);
	return rt;	
}

int update(int l, int r, int x, int val, int rt) {
	int cur = ++cnt;
	tree[cur] = tree[rt];
	if (l == r) {
		tree[cur].val = val;
		return cur;
	}
	int mid = (l + r) / 2;
	if (x <= mid) {
		tree[cur].l = update(l, mid, x, val, tree[rt].l);
	} else tree[cur].r = update(mid + 1, r, x, val, tree[rt].r);
	return cur;
}

int query(int l, int r, int x, int rt) {
	if (l == r) return tree[rt].val;
	int mid = (l + r) / 2;
	if (x <= mid)  return query(l, mid, x, tree[rt].l);
	else return query(mid + 1, r, x, tree[rt].r);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> arr[i];
	}
	root[0] = build(1, n);
	rep(i, 1, m) {
		int v, op;
		cin >> v >> op;
		if (op == 1) {
			int p, c;
			cin >> p >> c;
			root[i] = update(1, n, p, c, root[v]);
		} else {
			int p;
			cin >> p;
			root[i] = root[v];
			cout << query(1, n, p, root[i]) << '\n';
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
