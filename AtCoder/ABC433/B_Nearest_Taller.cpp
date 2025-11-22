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

int n, arr[105];
main() {
//	int t; cin >> t; while (t--) solve();
cin >> n; rep(i, 1, n) cin >> arr[i];
	rep(i, 1, n) {
		rrep(j, 1, i) {
			if (arr[j] > arr[i]) {
				cout << j << '\n';
				goto _;
			}
		}
		cout << "-1\n";
		_:;
	}
	return 0;
}
