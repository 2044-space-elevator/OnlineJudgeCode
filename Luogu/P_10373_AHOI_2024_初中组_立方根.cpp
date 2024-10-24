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

#define int ll

main() {
//	int t; cin >> t; while (t--) solve();
	int last = 1, now = 0;
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		rep(i, last, 2e4) {
			int p = i * i * i;
			if (p > x) {
				last = i;
				break;
			}
			now += (p - (i - 1) * (i - 1) * (i - 1)) * (i - 1);
		}
		int tmp = now  + (last - 1) * (x - (last - 1) * (last - 1) * (last - 1) + 1) ;
		cout << tmp << endl;
	}
	return 0;
}
