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

int n, F, arr[2005], dp[2];


main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> F;
	int sum = 0;
	rep(i, 1, n) {
		cin >> arr[i];
		sum += arr[i];
	}
	int k = sum / F;
	// 
	// O (k^3 * N * F )
	return 0;
}
