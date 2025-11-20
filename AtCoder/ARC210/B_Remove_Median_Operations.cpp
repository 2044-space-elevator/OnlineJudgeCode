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

const int N = 1e6 + 5;
int n, m, q;
ll arr[N], brr[N], times[N], ls[N], cnt;

struct ques {
	bool type;
	int ind; ll val;
}ques[N];

struct Tree {
	int l, r;
	ll times, val;
}tree[N * 5];

#define lc (2*p)
#define rc (2*p+1)

void pushUp(int p) {
	tree[p].times = tree[lc].times + tree[rc].times;
	tree[p].val = tree[lc].val + tree[rc].val;
}

void build(int p, int l, int r) {
	tree[p].l = l, tree[p].r = r;
	if (l == r) {
		tree[p].times = times[l];
		tree[p].val = tree[p].times * ls[l];
		return;
	}
	int mid = (l + r) / 2;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushUp(p);
}

void update(int p, int x, int val) {
	if (tree[p].l == x && x == tree[p].r) {
		tree[p].times += val;
		tree[p].val = tree[p].times * ls[x];
		return;
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	if (x <= mid) update(lc, x, val);
	if (x > mid) update(rc, x, val);
	pushUp(p);
}

Tree query(int p, int l, int r) {
	if (tree[p].l >= l && r >= tree[p].r) {
		return tree[p];
	}
	int mid = (tree[p].l + tree[p].r) / 2;
	Tree ans = {0, 0, 0, 0};
	if (l <= mid) {
		Tree tmp = query(lc, l, r);
		ans.times += tmp.times;
		ans.val += tmp.val;	
	} if (r > mid) {
		Tree tmp = query(rc, l, r);
		ans.times += tmp.times;
		ans.val += tmp.val;
	}
	pushUp(p);
	return ans;
}

main() {
	ll total_sum = 0;
	cin >> n >> m >> q;
	rep(i, 1, n) { cin >> arr[i]; ls[++cnt] = arr[i]; total_sum += arr[i];}
	rep(i, 1, m) { cin >> brr[i]; ls[++cnt] = brr[i]; total_sum += brr[i]; }
	rep(i, 1, q) {
		int typ;
		int ind, val;
		cin >> typ >> ind >> val;
		ls[++cnt] = val;
		ques[i] = {(bool)(typ - 1), ind, val};
	}
	sort(ls + 1, ls + cnt + 1);
	cnt = unique(ls + 1, ls + cnt + 1) - (ls + 1);
	rep(i, 1, n) {
		int pos = lower_bound(ls + 1, ls + cnt + 1, arr[i]) - ls;
		times[pos]++;
	}
	rep(i, 1, m) {
		int pos = lower_bound(ls + 1, ls + cnt + 1, brr[i]) - ls;
		times[pos]++;
	}
	build(1, 1, cnt);
	rep(i, 1, q) {
		int ind = ques[i].ind; ll val = ques[i].val;
		if (!ques[i].type) {
			int reduce_pos = lower_bound(ls + 1, ls + cnt + 1, arr[ind]) - ls;
			int add_pos = lower_bound(ls + 1, ls + cnt + 1, val) - ls;
			total_sum -= arr[ind]; total_sum += val;
			times[reduce_pos]--;
			times[add_pos]++;
			arr[ind] = val;
			update(1, reduce_pos, -1);
			update(1, add_pos, 1);
		} else {
			int reduce_pos = lower_bound(ls + 1, ls + cnt + 1, brr[ind]) - ls;
			int add_pos = lower_bound(ls + 1, ls + cnt + 1, val) - ls;
			total_sum -= brr[ind]; total_sum += val;
			times[reduce_pos]--;
			times[add_pos]++;
			brr[ind] = val;
			update(1, reduce_pos, -1);
			update(1, add_pos, 1);
		}
		int l = 1, r = cnt, begin_pos = 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (query(1, 1, mid).times >= (n) / 2) {
				begin_pos = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		ll ans = total_sum;
		Tree begin = query(1, 1, begin_pos);
		ans -= (begin.times - (n) / 2) * ls[begin_pos];
		l = 1, r = cnt;
		int end_pos = l;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (query(1, 1, mid).times >= (n) / 2 + m) {
				end_pos = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		Tree end = query(1, 1, end_pos);
		// cout << end_pos << ' ' << end.times << ' ';
		ans -= end.val - begin.val;
		ans += (end.times - (n) / 2 - m) * ls[end_pos];
		// cout << (begin.times - (n + 1) / 2) * ls[begin_pos] << ' ' << end.val - begin.val << ' ' << (end.times - (n + 1) / 2 - m) * ls[end_pos] << ' ' << ls[end_pos] << ' ' << ' ';	
		cout << ans << '\n';
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
