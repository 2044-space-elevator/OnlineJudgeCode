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

int n;
int d[(int)1e6 + 5], dp[(int)1e6 + 5];


main() {
	cin >> n;
	rep(i, 1, n) {
		cin >> d[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		deque<int> q;
		q.push_back(1);
		rep(i, 2, n) {
			while(q.size() && i - q.front() > k) q.pop_front();
			dp[i] = dp[q.front()] + (d[q.front()] <= d[i]);
			while(q.size() && dp[q.back()] > dp[i] || (dp[q.back()] == dp[i] && d[q.back()] < d[i])) q.pop_back();
			q.push_back(i);
		}
		cout << dp[n] << '\n';

	}
//	int t; cin >> t; while (t--) solve();
	return 0;
}
