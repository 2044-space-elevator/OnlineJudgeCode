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

const int N = 1E6 + 5;
int dp[N], arr[N], n;
deque<int> q;

void solve() {
	memset(dp, 127, sizeof dp);
	dp[1] = 0;
	q.clear();
	q.push_back(1);
	int ki;
	cin >> ki;	
	rep(i, 2, n) {
		while (q.size() && q.front() < i - ki) {
			q.pop_front();
		}
		dp[i] = dp[q.front()] + (arr[i] >= arr[q.front()]);
		while (q.size() && dp[q.back()] > dp[i] || (dp[i] == dp[q.back()] && arr[q.back()] <= arr[i])) {
			q.pop_back();
		}
		q.push_back(i);
	}
	cout << dp[n] << endl;
}


main() {
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i];
	}	
	int t; cin >> t; while (t--) solve();
	return 0;
}
