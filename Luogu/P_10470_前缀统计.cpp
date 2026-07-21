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

const int N = 1E6 + 5;
int tr[N][26], cnt, exist[N];

void insert(stg s) {
	int p = 0;
	for (char v : s) {
		if (!tr[p][v]) tr[p][v] = ++cnt;
		p = tr[p][v];
	}
	exist[p]++;
}

int find(stg s) {
	int p = 0;
	int ans = 0;
	for (char v : s) {
		if (!tr[p][v]) tr[p][v] = ++cnt;
		p = tr[p][v];
		ans += exist[p];
	}
	return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
int n, m;
cin >> n >> m;
	rep(i, 1, n) {
		stg a;
		cin >> a;
		insert(a);
	}
	rep(i, 1, m) {
		stg fd;
		cin >> fd;
		int ans = find(fd);
		cout << ans << '\n';
	}
	return 0;
}
