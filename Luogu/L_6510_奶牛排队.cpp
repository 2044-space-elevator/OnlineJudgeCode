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

int n, arr[(int)1e5 + 5], ans = 0;

int s1[(int)1e5 + 5], s2[100005], t1, t2;
main() {
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i];
	}
	rep(i, 1, n) {
		while (t1 && arr[s1[t1]] >= arr[i]) t1--;
		while (t2 && arr[s2[t2]] < arr[i]) t2--;
		int k = upper_bound(s1 + 1, s1 + 1 + t1, s2[t2]) - s1;
		if (k != t1 + 1) { ans = max(ans, i - s1[k] + 1); }
		s1[++t1] = s2[++t2] = i;
	}
	cout << ans << '\n';
//	int t; cin >> t; while (t--) solve();

	return 0;
}
