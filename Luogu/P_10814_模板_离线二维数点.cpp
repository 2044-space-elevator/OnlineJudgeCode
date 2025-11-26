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

const int N = 2E6 + 5;
int n, m, cnt;
int tr[N << 6], ls[N << 6], rs[N << 6], arr[N], rt[N];

void update(int &rt, int p, int pl, int pr, int x) {
	rt = ++cnt;
	ls[rt] = ls[p], rs[rt] = rs[p], tr[rt] = tr[p] + 1;
	if (pl == pr) return;
	int mid = (pl + pr) / 2;
	if (x <= mid) update(ls[rt], ls[p], pl, mid, x);
	else update(rs[rt], rs[p], mid + 1, pr, x);
}

int query(int p, int pl, int pr, int k, int sum) {
	if (pl == pr) return tr[p];
	int mid = (pl + pr) / 2;	
	if (k <= mid) return sum + query(ls[p], pl, mid, k, 0);
	else return sum + tr[ls[p]] + query(rs[p], mid + 1, pr, k, pr); 
}


main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> arr[i];
		update(rt[i], rt[i - 1], 1, N, arr[i]);
	}
	rep(i, 1, m) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << query(rt[r], 1, N, k, 0) - query(rt[l - 1], 1, N, k, 0) << '\n';

	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
