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

ll reds_pref[N], reds_len[N];
ll cover[N];
ll v[N], w[N];

bool cmp(RedSegment a, RedSegment b) {
	return a.l < b.l;
}

bool check(int red, pair<int, int> blue) {
	return max(blue.first, reds[red].l) <= min(blue.second, reds[red].r);
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
		reds_len[i] = reds_len[i - 1] + reds[i].r - reds[i].l + 1;
	}
	// cout << check(1, {18, 19});
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
		if (right_red - left_red >= 0) {
			w[i] = reds_pref[right_red] - reds_pref[left_red - 1];
			int tmpl = left_red, tmpr = right_red;
			if (reds[left_red].l < lef) {
				v[i] = reds[left_red].r - lef + 1;
				tmpl++;
			}
			if (reds[right_red].r > rig) {
				v[i] = rig - reds[right_red].l + 1;
				tmpr--;
			}
			if (right_red - left_red >= 0)	
				v[i] += reds_len[tmpr] - reds_len[tmpl - 1];
		}

		cout << left_red << ' ' << right_red << ' ' << v[i] << ' ' << w[i] << endl;
	}
	return 0;
}
