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

const int N = 1E7 + 5;
int ls[N], rs[N], st[N], top, lst, arr[N];

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i];
		top = lst;
		while (top && arr[st[top]] > arr[i]) top--;
		if (top) rs[st[top]] = i;
		if (top < lst) ls[i] = st[top + 1];
		st[++top] = i;
		lst = top;
	}
	ll ans1 = 0, ans2 = 0;
	rep(i, 1, n) {
		ans1 ^= (ll)(i) * (ls[i] + 1);
		ans2 ^= (ll)(i) * (rs[i] + 1);
	}
	cout << ans1 << ' ' << ans2;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
