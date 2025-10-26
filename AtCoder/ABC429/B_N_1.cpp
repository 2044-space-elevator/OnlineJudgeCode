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

int arr[105];
main() {
	int n;
	int sum = 0;
	cin >> n;
	int m;
	cin >> m;
	rep(i, 1, n) {
		cin >> arr[i];
		sum += arr[i];
	}
	rep(i, 1, n) {
		if (sum - arr[i] == m) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
//	int t; cin >> t; while (t--) solve();
	return 0;
}
