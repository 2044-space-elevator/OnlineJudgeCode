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

int n, q;
const int N = 1E6 + 5;
int arr[N], B, bel[N], bl[N], br[N];
const int bsz = 1E3 + 5;
int sorted[bsz][bsz], lazy[bsz];

void init() {
	for (int i = 1; i <= bsz; i++) {
		bl[i] = (i - 1) * bsz + 1;
		br[i] = i * bsz;
		if (br[i] >= n) {
			br[i] = n;
			B = i;
			break;
		}
	}
	for (int i = 1; i <= B; i++) {
		for (int j = bl[i]; j <= br[i]; j++) {
			bel[j] = i;
		}
	}
	for (int i = 1; i <= B; i++) {
		for (int j = bl[i]; j <= br[i]; j++) {
			sorted[i][j - bl[i] + 1] = arr[j];
		}	
		sort(sorted[i] + 1, sorted[i] + br[i] - bl[i] + 2);
	}
}

void update(int l, int r, int v) {
	if (bel[l] + 1 >= bel[r]) {
		for (int i = l; i <= r; i++) {
			arr[i] += v;
		}
		for (int i = bel[l]; i <= bel[r]; i++) {
			for (int j = bl[i]; j <= br[i]; j++) {
				sorted[i][j - bl[i] + 1] = arr[j];
			}
			sort(sorted[i] + 1, sorted[i] + br[i] - bl[i] + 2);
		}
		return;
	}
	for (int i = l; i <= br[bel[l]]; i++) {
		arr[i] += v;
	}
	for (int i = bl[bel[r]]; i <= r; i++) {
		arr[i] += v;
	}
	// for (int j = bl[bel[l]]; j <= br[bel[l]]; j++) {
	// 	sorted[bel[l]][j - bl[bel[l]] + 1] = arr[j];
	// }
	// for (int j = bl[bel[r]]; j <= br[bel[r]]; j++) {
	// 	sorted[bel[r]][j - bl[bel[r]] + 1] = arr[j];
	// }
	// sort(sorted[bel[r]] + 1, sorted[bel[r]] + br[bel[r]] - bl[bel[l]] + 2);
	// sort(sorted[bel[l]] + 1, sorted[bel[l]] + br[bel[l]] - bl[bel[l]] + 2);
	for (int i = bel[l] + 1; i < bel[r]; i++) {
		lazy[i] += v;
	}
}

int query(int l, int r, ll v) { 
	int ans = 0;
	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; i++) {
			if (lazy[bel[l]] + arr[i] >= v) ans++;			
		}
		return ans;
	}
	for (int i = l; i <= br[bel[l]]; i++) {
		if (lazy[bel[l]] + arr[i] >= v) ans++;
	}
	for (int i = bl[bel[r]]; i <= r; i++) {
		if (lazy[bel[r]] + arr[i] >= v) ans++;
	}
	for (int i = bel[l] + 1; i < bel[r]; i++) {
		int pos = lower_bound(sorted[i] + 1, sorted[i] + br[i] - bl[i] + 2, v - lazy[i]) - sorted[i];
		ans += br[i] - bl[i] + 1 - pos + 1;
	}
	return ans;
}

main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init();
	while (q--) {
		char c;
		cin >> c;
		if (c == 'A') {
			int l, r, c;
			cin >> l >> r >> c;
			cout << query(l, r, c)  << '\n';
		} else {
			int l, r, c;
			cin >> l >> r >> c;
			update(l, r, c);
		}
	}
	//	int t; cin >> t; while (t--) solve();
	return 0;
}
