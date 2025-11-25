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

struct SegmentTree {
	int lc, rc, val;
}tr[N << 6];

int tot;
int build(int l, int r) {
	int rt = ++tot;
	if (l == r) return rt;
	int mid = (l + r) / 2;
	tr[rt].lc = build(l, mid);
	tr[rt].rc = build(mid + 1, r);
	return rt;	
}

int update(int rt, int pl, int pr, int k) {
	int cur = ++tot;
	tr[cur] = tr[rt];
	tr[cur].val = tr[rt].val + 1;
	if (pl == pr) {
		return cur;
	}
	int mid = (pl + pr) / 2;
	if (k <= mid) tr[cur].lc = update(tr[cur].lc, pl, mid, k);
	if (k > mid) tr[cur].rc = update(tr[cur].rc, mid + 1, pr, k);
	return cur;
}

int query(int u, int v, int l, int r, int val) {
	if (l == r) return l;
	int mid = (l + r) / 2;
	int sum = tr[tr[v].lc].val - tr[tr[u].lc].val;
	if (val <= sum) {
		return query(tr[u].lc, tr[v].lc, l, mid, val);
	}	 else return query(tr[u].rc, tr[v].rc, mid + 1, r, val - sum);
}
int n, m, arr[N], cnt, lsh[N], rt[N];
int find(int val) {
	return lower_bound(lsh + 1, lsh + cnt + 1, val) - lsh;
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	rep(i ,1, n) cin >> arr[i];
	rep(i, 1, n) lsh[i] = arr[i];
	sort(lsh + 1, lsh + n + 1);
	cnt = unique(lsh + 1, lsh + n + 1) - (lsh + 1);
	rt[0] = build(1, cnt);
	rep(i, 1, n) rt[i] = update(rt[i - 1], 1, cnt, find(arr[i]));
	while (m--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << lsh[query(rt[l - 1], rt[r], 1, cnt, k)] << '\n';
	}
	return 0;
}
