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


const int N = 4E5 + 5;
int n, q, lsh[N], cnt;
int ql[N], qr[N], tr[N * 16], len[N * 16];
pair<int, int> seg[N];

int find(int val) {
	return lower_bound(lsh + 1, lsh + cnt + 1, val) - (lsh);
}

#define lc (2*p)
#define rc (2*p+1)
void pushUp(int p, int pl, int pr) {
	if (tr[p]) len[p] = lsh[pr + 1] - lsh[pl];
	else if (pl == pr) len[p] = 0;
	else len[p] = len[lc] + len[rc];
}

void update(int p, int pl, int pr, int l, int r, int k) {
	if (l <= pl && pr <= r) {
		tr[p] += k;
		pushUp(p, pl, pr);
		return ;
	}
	int mid = (pl + pr) / 2;
	if (l <= mid) update(lc, pl, mid, l, r, k);
	if (r > mid) update(rc, mid + 1, pr, l, r, k);
	pushUp(p, pl, pr);
}


main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> q;
	rep(i, 1, q) {
		cin >> ql[i] >> qr[i];
		lsh[++cnt] = ql[i], lsh[++cnt] = qr[i] + 1;		
	}	
	sort(lsh + 1, lsh + cnt + 1);
	cnt = unique(lsh + 1, lsh + cnt + 1) - (lsh + 1);
	rep(i, 1, q) {
		int L = find(ql[i]);
		int R = find(qr[i] + 1) - 1;
		update(1, 1, cnt - 1, L, R, 1);
		cout << n - len[1] << '\n';
	}		
	return 0;
}
