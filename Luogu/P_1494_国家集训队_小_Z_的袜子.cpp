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

const int N = 50005;
int cnt[N], col[N];
ll sum, n, m;
ll ans1[N], ans2[N];
struct que {
	int l, r, id;
}query[N];

int maxn;
bool cmp(const que &a, const que &b) {
	return (a.l / maxn == b.l / maxn) ? a.l < b.l : a.r < b.r;
}

void add(int i) {
	sum += cnt[i];
	cnt[i]++;
}

void del(int i) {
	cnt[i]--;
	sum -= cnt[i];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	maxn = sqrt(n);
	rep(i, 1, n) cin >> col[i];
	rep(i, 1, m) {
		int l, r;
		cin >> l >> r;
		query[i] = {l, r, i};
	}
	sort(query + 1, query + m + 1, cmp);
	int l = 1, r = 0;
	rep(i, 1, m) {
		if (query[i].l == query[i].r) {
			ans1[query[i].id] = 0;
			ans2[query[i].id] = 1;
			continue;
		}
		while (query[i].l < l) add(col[--l]);
		while (query[i].r > r) add(col[++r]);
		while (query[i].l > l) del(col[l++]);
		while (query[i].r < r) del(col[r--]);
		ans1[query[i].id] = sum;
		ans2[query[i].id] = (ll)(r - l + 1ll) * (r - l) / 2ll;
	}
	rep(i, 1, m) {
		if (ans1[i]) {
			ll gc = __gcd(ans1[i], ans2[i]);
			ans1[i] /= gc, ans2[i] /= gc;
			cout << ans1[i] << '/' << ans2[i] << '\n';
		} else cout << "0/1\n";
	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
