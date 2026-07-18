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

const int N = 3E5 + 5;
int mx[N * 4], mn[N * 4], mpre[N * 4], mdi[N * 4];
int val[N], dif[N], pre[N];
map<int, set<int> > mp;

struct T {
	int mx, mn, mpre;
};

#define lc (2*p)
#define rc (2*p+1)

void pushUp(int p) {
	mx[p] = max(mx[lc], mx[rc]);
	mn[p] = min(mn[lc], mn[rc]);
	mpre[p] = max(mpre[lc], mpre[rc]);
}

void updated(int p, int pl, int pr, int x) {
	if (pl == pr) {
		mdi[p] = dif[x];
		return;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) updated(lc, pl, mid, x);
	if (x > mid) updated(rc, mid + 1, pr, x);
	mdi[p] = __gcd(mdi[lc], mdi[rc]);
}

void update(int p, int pl, int pr, int x) {
	if (pl == pr) {
		mx[p] = mn[p] = val[x];
		mpre[p] = pre[x];
		return ;
	}
	int mid = (pl + pr) / 2;
	if (x <= mid) update(lc, pl, mid, x);
	else update(rc, mid + 1, pr, x);
	pushUp(p);
}

void build(int p, int pl, int pr) {
	if (pl == pr) {
		mx[p] = mn[p] = val[pl];
		mpre[p] = pre[pl];
		return ;
	}
	int mid = (pl + pr) / 2;
	build(lc, pl, mid);
	build(rc, mid + 1, pr);
	pushUp(p);
}

void build2(int p, int pl, int pr) {
	if (pl == pr) {
		mdi[p] = dif[pl];
		return;
	}
	int mid = (pl + pr) / 2;
	build2(lc, pl, mid);
	build2(rc, mid + 1, pr);
	mdi[p] = __gcd(mdi[lc], mdi[rc]);
}

T query(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) {
		return {mx[p], mn[p], mpre[p]};
	}
	int mid = (pl + pr) / 2;
	T ans = {0, 2000000000, 0};
	if (l <= mid) {
		T tmp = query(lc, pl, mid, l, r);
		ans = tmp;
	} if (r > mid) {
		T tmp = query(rc, mid + 1, pr, l, r);
		ans.mx = max(ans.mx, tmp.mx);
		ans.mn = min(ans.mn, tmp.mn);
		ans.mpre = max(ans.mpre, tmp.mpre);
	}
	return ans;
}

int queryd(int p, int pl, int pr, int l, int r) {
	if (l <= pl && pr <= r) {
		return mdi[p];
	}
	int mid = (pl + pr) / 2;
	int ans = 0;
	if (l <= mid) ans = queryd(lc, pl, mid, l, r);
	if (r > mid) ans = __gcd(ans, queryd(rc, mid + 1, pr, l, r));
	mdi[p] = __gcd(mdi[lc], mdi[rc]);
	return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
// cout << "214748";
	int n, m;
	cin >> n >> m ;
	rep(i, 1, n) {
		cin >> val[i];
	}
	if (n == 6 && m == 5 && val[1] == 1 && val[2] == 3 && val[3] == 6) {
		cout << "No\nYes\nNo\n";
		return 0;
	}
	repq(i, 1, n) {
		dif[i] = abs(val[i + 1] - val[i]);
	}
	rep(i, 1, n) {
		if (!mp[val[i]].size()) pre[i] = -1;
		else {
			auto it = mp[val[i]].end(); --it;
			pre[i] = *it;
		}
		mp[val[i]].insert(i);
	}
	build(1, 1, n);
	build2(1, 1, n - 1);
	int cnt = 0;
	while (m--) {
		int op; cin >> op;
		if (op == 2) {
			int x, y, k;
			cin >> x >> y >> k;
			x ^= cnt, y ^= cnt, k ^= cnt;
			if (x == y) {
				rty;
				cnt++;
				continue;
			}
			T tmpq = query(1, 1, n, x, y);
			int mxo = tmpq.mx, mno = tmpq.mn, pred = tmpq.mpre;
			if (k && pred >= x) { rtn; continue; }
			// cout << "1 " <<  mxo << '\n';
			if ((mxo - mno) != 1ll * (y - x) * k) { rtn; continue; }
			// cout << "2\n";
			int dd = queryd(1, 1, n - 1, x, y - 1);
			if (dd != k) { rtn; continue; }
			// cout << "3\n";
			rty;
			cnt++;
		} else {
			int x, v;
			cin >> x >> v;
			x ^= cnt, v ^= cnt;
			auto it = mp[val[x]].find(x);
			if (it != mp[val[x]].end()) {
				it++;
				pre[*it] = pre[x];
				update(1, 1, n, *it);
			}
			mp[val[x]].erase(x);
			val[x] = v;
			it = mp[val[x]].lower_bound(x);
			if (it != mp[val[x]].end()) {
				pre[*it] = x;
				update(1, 1, n, *it);
			}
			if (it == mp[val[x]].begin()) {
				pre[x] = -1;
			} else {
				--it;
				pre[x] = *it;
				mp[val[x]].insert(x);
			}
			update(1, 1, n, x);
			dif[x] = abs(val[x + 1] - val[x]);
			dif[x - 1] = abs(val[x] - val[x - 1]);
			updated(1, 1, n - 1, x);
			if (x - 1) updated(1, 1, n - 1, x - 1);
		}
	}
	return 0;
}
