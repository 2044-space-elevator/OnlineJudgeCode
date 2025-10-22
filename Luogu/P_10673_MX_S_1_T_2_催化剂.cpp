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


const int N = 5E6 + 5;
struct SegmentTree {
	int l, r, val, val2;
}tree[N * 4];
int arr[N], mp[N], brr[N];

#define lc (2*p)
#define rc (2*p+1)
void pushUp(int p) {
	tree[p].val2 = tree[lc].val2 + tree[rc].val2;
	tree[p].val = tree[lc].val + tree[rc].val;
}

void build(int p, int l, int r) {
	tree[p].l = l, tree[p].r = r;
	if (l == r) {
		tree[p].val2 = brr[l];
		tree[p].val = brr[l] * l;
		return;
	}
	int mid = (l + r) / 2;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushUp(p);
}

void update(int p, int x, int val) {
	if (x == tree[p].l && tree[p].r == x) {
		tree[p].val = brr[x] * x;
		tree[p].val2 = brr[x];
		return;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	if (x <= mid) update(lc, x, val);
	if (x > mid) update(rc, x, val);
	pushUp(p);
}

int query(int p, int l, int r, ll k) {
	if (l <= tree[p].l && tree[p].r <= r) {
		return tree[p].val - k * tree[p].val2;	
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	int ans = 0;
	if (l <= mid) ans += query(lc, l, r, k);
	if (r > mid) ans += query(rc, l, r, k);
	pushUp(p);
	return ans;
}


main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> arr[i];
		mp[arr[i]]++;
	}
	rep(i, 1, n) {
		brr[mp[i]]++;
	}
	// rep(i, 1, n) {
	// 	cout << brr[i] << ' ';
	// }
	build(1, 1, N);
	while (m--) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			brr[mp[x]]--;
			brr[mp[x] + 1]++;
			update(1, mp[x], -1);
			update(1, mp[x] + 1, 1);
			mp[x]++;
		}
		if (op == 2) {
			brr[mp[x]]--;
			brr[mp[x] - 1]++;
			update(1, mp[x], -1);
			if (mp[x] - 1)
				update(1, mp[x] - 1, 1);
			mp[x]--;
		}
		if (op == 3) {
			cout << query(1, x + 1, N, x) << '\n';
		}
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
