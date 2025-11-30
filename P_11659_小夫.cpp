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
int n, m;
const int N = 4E5 + 5;
ll arr[N], sum, cnt[N], cnt42[N], cnt23[N], blksi, ans[N];

struct que {
	int l, r, id;
}query[N];

bool cmp(que &a, que &b) {
	if (a.l / blksi == b.l / blksi) return a.r < b.r;
	return a.l < b.l;
}

main() {
	cin >> n >> m;
	rep(i ,1, n) cin >> arr[i];
	blksi = sqrt(n);
	rep(i ,1, m) {
		int l, r;
		cin >> l >> r;
		query[i] = {l, r, i};
	}
	sort(query + 1, query + m + 1, cmp);
	int l = 1, r = 0;
	rep(i, 1, m) {
		while (query[i].l < l) {
			l--;
			if (arr[l] % 4 == 0) sum += cnt23[arr[l] / 4];
			if (arr[l] % 4 == 0) cnt42[arr[l] / 4] += cnt[arr[l] / 2];
			if (arr[l] % 2 == 0) cnt23[arr[l] / 2] += cnt[arr[l] / 2 * 3];
			cnt[arr[l]]++;
		}	
		while (query[i].r > r) {
			r++;
			if (arr[r] % 3 == 0) sum += cnt42[arr[r] / 3];
			if (arr[r] % 2 == 0) cnt42[arr[r] / 2] += cnt[arr[r] * 2];
			if (arr[r] % 3 == 0) cnt23[arr[r] / 3] += cnt[arr[r] / 3 * 2];
			cnt[arr[r]]++;
		}
		while (query[i].l > l) {
			cnt[arr[l]]--;
			if (arr[l] % 2 == 0) cnt23[arr[l] / 2] -= cnt[arr[l] / 2 * 3];
			if (arr[l] % 4 == 0) cnt42[arr[l] / 4] -= cnt[arr[l] / 2];
			if (arr[l] % 4 == 0) sum -= cnt23[arr[l] / 4];
			l++;
		}
		while (query[i].r < r) {
			cnt[arr[r]]--;
			if (arr[r] % 3 == 0) cnt23[arr[r] / 3] -= cnt[arr[r] / 3 * 2];
			if (arr[r] % 2 == 0) cnt42[arr[r] / 2] -= cnt[arr[r] * 2];
			if (arr[r] % 3 == 0) sum -= cnt42[arr[r] / 3];
			r--;
		}
		ans[query[i].id] = sum;
	}
	rep(i, 1, m) cout << ans[i] << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
