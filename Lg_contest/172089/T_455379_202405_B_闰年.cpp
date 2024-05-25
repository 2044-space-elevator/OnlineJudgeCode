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

#define rt0 return 0;

main() {
//	int t; cin >> t; while (t--) solve();
	int y;
	cin >> y;
	if (y % 4) {
		rtn
		rt0
	}
	if (!(y % 4) && y % 100) {
		rty
		rt0
	}
	if (!(y % 100) && y % 400) {
		rtn
		rt0
	}
	if (!(y % 400) && y % 3200) {
		rty
		rt0
	}
	if (!(y % 3200) && y % 172800) {
		rtn
		rt0
	}
	if (!(y % 172800)) {
		rty
		rt0
	}
	return 0;
}
