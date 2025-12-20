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

const int N = 4E5 + 5;
int n, m;
int x[N], y[N];
map<int, vector<int> > _m;

bool valid(int xi, int yi) {
	for (int v : _m[xi]) {
		if (y[v] == yi || y[v] + 1 == yi) return 0;
	}
	return 1;
}

main() {
//	int t; cin >> t; while (t--) solve();
	cin >> n >> m;
	int ans = 0;
	rep(i, 1, m) {
		cin >> x[i] >> y[i];
		if (valid(x[i], y[i]) && valid(x[i], y[i] + 1) && valid(x[i] + 1, y[i]) && valid(x[i] + 1, y[i] + 1))	 
		{
			ans++;
			_m[x[i]].push_back(i);
			_m[x[i] + 1].push_back(i);
		}
	}
	cout << ans;
	return 0;
}
