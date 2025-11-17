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

ll arr[(int)1e5 + 5], sum[(int)1e5 + 5];

void solve() {
	int n;
	cin >> n;
	rep(i ,1, n) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}	
	rep(i, 1, n - 1) {
		if (sum[i] > sum[n] - sum[i]) {
			cout << 1;
		} else if (arr[i] > arr[i + 1] && sum[i] + arr[i + 1] > sum[n] - sum[i] - arr[i + 1]) cout << 1; 
		else cout << 0;
	}
	cout << '\n';
}


main() {
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/Lenovo/Desktop/war6.in", "r", stdin);
		freopen("C:/Users/Lenovo/Desktop/war6.out", "w", stdout);
	#endif
	int t; cin >> t; while (t--) solve();
	return 0;
}
