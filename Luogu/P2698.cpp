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

int n, d;
const int N = 1E6 + 5;
pair<int, int> drops[N];

bool check(int x) {
	deque<int> q1, q2;
	rep(i, 1, n) {
		while (q1.size() && drops[q1.back()].second <= drops[i].second) {
			q1.pop_back();
		}
		q1.push_back(i);
		while (drops[q1.front()].first < drops[i].first - x) q1.pop_front();

		while (q2.size() && drops[q2.back()].second >= drops[i].second) {
			q2.pop_back();
		}
		q2.push_back(i);
		while (drops[q2.front()].first < drops[i].first - x) q2.pop_front();
		if (q1.size() && q2.size()) {
			if (drops[q1.front()].second - drops[q2.front()].second >= d) return 1;
		}
	}
	return 0;	
}

main() {
	cin >> n >> d;
	int maxx = 0;
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		drops[i] = {x, y};
		maxx = max(maxx, x);
	}
	sort(drops + 1, drops + n + 1);
	int l = 1, r = maxx + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else l = mid + 1;
	}
	if (!check(maxx)) {
		cout << "-1\n";
	} else 
	cout << l; 
//	int t; cin >> t; while (t--) solve();
	return 0;
}
