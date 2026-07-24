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
const int N = 2E6 + 5;
ll w[N], sum[N], pre[N], p, d;

main() {
	cin >> n >> p >> d;
	rep(i, 1, n) {
		cin >> w[i];
		w[i] += w[i - 1];
	}	
	deque<int> q;
	rep(i, d, n) {
		pre[i] = w[i] - w[i - d];
	}
	int ans = d;
	q.push_back(d);
	int lst = 1;
	rep(i, d + 1, n) {
		while (q.size() && pre[i] > pre[q.back()]) q.pop_back();
		q.push_back(i);
		while (q.size() && q.front() - lst + 1 < d) q.pop_front();
		while (q.size() && w[i] - w[lst - 1] - pre[q.front()] > p) {
			lst++;
			while (q.size() && q.front() - lst + 1 < d) q.pop_front();
		}
		ans = max(ans, i - lst + 1);
	}
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
