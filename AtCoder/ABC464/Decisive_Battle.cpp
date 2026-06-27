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


main() {
	stg s;
	cin >> s;
	int cnt1 = 0;
	for (char v : s) {
		if (v == 'E') cnt1++;
	}
	if (cnt1 > s.size() - cnt1) {
		cout << "East\n";
	} else cout << "West\n";
//	int t; cin >> t; while (t--) solve();
	return 0;
}
