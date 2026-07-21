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

const int N = 4E6 + 5;
int arr[N];
int tr[N][32], cnt;
bool exist[N];

void insert(int v) {
	int p = 0;
	rrep(i, 0, 30) {
		int c = 0;
		if (v & (1ll << i)) {
			c = 1;
		}
		if (!tr[p][c]) tr[p][c] = ++cnt;
		p = tr[p][c];
	}
}

int find(int v) {
	int p = 0;
	int ans = 0;
	rrep(i, 0 ,30) {
		int c = !(v & (1ll << i));
		if (tr[p][c]) { p= tr[p][c]; ans |= (1 << i); }
		else p = tr[p][!c];
	}
	return ans;
}


main() {
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int x;
		cin >> x;
		insert(x);
		ans = max(ans, find(x));
	}
	cout << ans << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
