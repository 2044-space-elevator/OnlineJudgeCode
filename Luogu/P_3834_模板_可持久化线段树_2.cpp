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

const int N = 2E5 + 5;
struct ZXTree {
	int l, r, val;
}tree[N * 64];

int pos[N], len, cnt, root[N], arr[N], n, m;

int getpos(int val) {
	return lower_bound(pos + 1, pos + len + 1, val) - pos;
}

int build(int l, int r) {
	int rt = ++cnt;
	tree[rt].val = 0;
	if (l == r) return rt;
	int mid = (l + r) / 2;
	tree[rt].l = build(l, mid);
	tree[rt].r = build(mid + 1, r);
	return rt;
}

int update(int l, int r, int x, int rt) {
	int cur = ++cnt;
	tree[cur] = tree[rt];
	tree[cur].val++;
	if (l == r) return cur;
	int mid = (l + r) / 2;
	if (x <= mid) {
		tree[cur].l = update(l, mid, x, tree[cur].l);
	} else {
		tree[cur].r = update(mid + 1, r, x, tree[cur].r);
	}
	return cur;
}

int query(int l, int r, int L, int R, int val) {
	int mid = (L + R) / 2;
	int check = tree[tree[r].l].val - tree[tree[l].l].val;
	if (L == R) return L;
	if (val <= check) {
		return query(tree[l].l, tree[r].l, L, mid, val);
	} else return query(tree[l].r, tree[r].r, mid + 1, R, val - check);
}

main() {
	cin >> n >> m;
	rep(i ,1, n) {
		cin >> arr[i];
		pos[i] = arr[i];
	}
	sort(pos + 1, pos + n + 1);
	len = unique(pos + 1, pos + n + 1) - (pos + 1);
	rep(i, 1, n) {
		arr[i] = getpos(arr[i]); 
	}
	root[0] = build(1, len);
	rep(i ,1, n) {
		root[i] = update(1, len, arr[i], root[i - 1]);
	}
	while (m--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << pos[query(root[l - 1], root[r], 1, len, k)] << '\n';
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
