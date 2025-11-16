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

stg s;
int arr[10];

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> s;
	for (char v : s) {
		arr[v - '0']++;
	}
	rep(i, 1, 9) {
		if (arr[i]) {
			cout << i;
			arr[i]--;
			break;
		}
	}
	rep(i, 0, 9) {
		rep(j, 1, arr[i]) {
			cout << i;
		}
	}
	return 0;
}
