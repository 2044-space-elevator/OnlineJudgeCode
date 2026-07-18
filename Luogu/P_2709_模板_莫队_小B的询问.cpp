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

const int N = 5E4 + 5;
ll arr[N], cnt[N], sum, ans[N];
struct que {
	int l, r, id;
}query[N];
int BLKSIZE;

bool cmp(que &a, que &b) {
	if (a.l / BLKSIZE == b.l / BLKSIZE)
		return a.r < b.r;
	return a.l < b.l;
}

void add(int i) {
	sum += 2 * cnt[i] + 1;
	cnt[i]++;
}

void del(int i) {
	cnt[i]--;
	sum -= 2 * cnt[i] + 1;
}

main() {
	int n, m, k;
	cin >> n >> m >> k;
	BLKSIZE = sqrt(n);
	rep(i, 1, n) {
		cin >> arr[i];
	}
	rep(i, 1, m) {
		int l, r;
		cin >> l >> r;
		query[i] = {l, r, i};
	}
	sort(query + 1, query + m + 1, cmp);
	int l = 1, r = 0;
	rep(i, 1, m) {
		while (query[i].l < l) add(arr[--l]);
		while (query[i].r > r) add(arr[++r]);
		while (query[i].l > l) del(arr[l++]);
		while (query[i].r < r) del(arr[r--]);
		ans[query[i].id] = sum;
	}
	rep(i, 1, m) cout << ans[i] << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
