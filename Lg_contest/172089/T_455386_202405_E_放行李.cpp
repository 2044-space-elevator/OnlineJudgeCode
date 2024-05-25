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

int n;
bool arr[(int)1e6 + 5], brr[(int)1e6 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n;
	rep(i, 1, n) cin >> arr[i];
	rep(i, 1, n) cin >> brr[i];
	int p, q;
	cin >> p >> q;
	int minn = INT_MAX, max_p = 0;
	if (!p) {
		rep(i, 1, n) {
			if (abs(i - q) < minn) {
				if (!arr[i]) {
					minn = abs(i - q);
				}
				if (!brr[i]) {
					minn = abs(i - q);
				}
			}
		}
	}
	if (p) {
		rep(i, 1, n) {
			if (abs(i - q) < minn) {
				if (!brr[i]) {
					minn = abs(i - q);
				}
				if (!arr[i]) {
					minn = abs(i - q);
				}
			}
		}
	}
	if (minn == INT_MAX) {
		cout << -1;
		return 0;
	}	
	cout << max_p << ' ' << minn;
	return 0;
}
