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
struct RedSegment {
	int l, r;
	ll w;
}reds[N];

struct BlueSegment {
	int l, r;
	ll v, w;
}blues[N];

ll reds_pref[N], reds_len[N], dp[5005][5005], cnt, dp_pre[5005][5005], blue_l[5005];
ll cover[N];

bool cmp(RedSegment a, RedSegment b) {
	return a.l < b.l;
}

bool check(int red, pair<int, int> blue) {
	return max(blue.first, reds[red].l) <= min(blue.second, reds[red].r);
}

bool cmp2(BlueSegment a, BlueSegment b) {
	return a.l < b.l;
}

main() {
//	int t; cin >> t; while (t--) solve();
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, 1, n) 
		cin >> reds[i].l >> reds[i].r >> reds[i].w;
	sort(reds + 1, reds + n + 1, cmp);
	rep(i, 1, n) {
		reds_pref[i] = reds_pref[i - 1] + reds[i].w;
		// 权值的前缀和
		reds_len[i] = reds_len[i - 1] + reds[i].r - reds[i].l + 1;
		// 收益的前缀和
	}
	rep(i, 1, m) {
		int lef, rig;
		cin >> lef >> rig;
		int left_red = 1, r = n;
		int l = 1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (reds[mid].l > lef)
				r = mid - 1;
			else
				l = mid;
		}
		left_red = max(1, l);
		if (!check(left_red, {lef, rig})) {
			left_red++;
		}
		// 二分 si
		int right_red = 1; l = left_red, r = n;
		while (l < r) {
			int mid = (l + r) / 2;
			if (reds[mid].r < rig) 
				l = mid + 1;
			else
				r = mid;
		}
		right_red = min(n, r);
		if (!check(right_red, {lef, rig}))
			right_red--;
		// 二分 ti
		ll v = 0, w = 0;
		// 计算收益与代价
		if (right_red - left_red >= 0) {
			w = reds_pref[right_red] - reds_pref[left_red - 1];
			// 代价易得
			int tmpl = left_red, tmpr = right_red;
			if (reds[left_red].l < lef) {
				v = min(rig, reds[left_red].r) - max(reds[left_red].l, lef) + 1;
				tmpl++;
			}
			if (tmpr >= tmpl && reds[right_red].r > rig) {
				v += min(rig, reds[right_red].r) - max(lef, reds[right_red].l) + 1;
				tmpr--;
			}
			// 收益需要处理边际
			if (tmpr - tmpl >= 0)	
				v += reds_len[tmpr] - reds_len[tmpl - 1];
			blues[++cnt] = {left_red, right_red, v, w};
		}
	}
	sort(blues + 1, blues + cnt + 1, cmp2);
	rep(i, 1, cnt) {
		blue_l[i] = blues[i].l;
		// 因为我二分很烂 qwq，单开一个数组可以用 upper_bound（
	}
	ll ans = 0;
	rep(i, 1, cnt) {
		int ending = upper_bound(blue_l + 1, blue_l + cnt + 1, blues[i].r) - blue_l;
		rep(j, 0, k) {
			dp_pre[i][j] = max(dp_pre[i - 1][j], dp_pre[i][j]);
			if (j < blues[i].w) continue;
			dp[i][j] = dp_pre[i][j - blues[i].w] + blues[i].v;
			dp_pre[ending][j] = max(dp_pre[ending][j], dp[i][j]);
			ans = max(ans, dp[i][j]);
			// dp_pre 为 F 数组
			// 动规优化
		}
	}
	cout << ans;
	return 0;
}
