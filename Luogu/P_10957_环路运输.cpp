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

deque<int> q1;
int n;
int arr[(int)2e6 + 5];

main() {
	int maxe2 = -2e7;
	int ans = 0;
	cin >> n;
	rep(i, 1, n) {
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	rep(i, 1, n * 2) {
		while (q1.size() && q1.front() < i - n / 2) {
			q1.pop_front();
		}
		if (q1.size())
			ans = max(ans, arr[i] + i + arr[q1.front()] - q1.front());
		while (q1.size() && arr[q1.back()] - q1.back() <= arr[i] - i) q1.pop_back();
		q1.push_back(i);
	}
	cout << ans << '\n';
//	int t; cin >> t; while (t--) solve();
	return 0;
}
