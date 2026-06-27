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

const int N = 1E5 + 5;
pair<int, int> milk[N];
bool tag[N];
int n;
bool cmp(pair<int ,int > a, pair<int, int> b) {
	return a.first > b.first;
}

main() {
	cin >> n;
	ll ans = 0;
	rep(i, 1, n) cin >> milk[i].first >> milk[i].second;
	sort(milk + 1, milk + n + 1, cmp);
	rep(i, 1, n) {
		rrep(j, 1, milk[i].second) {
			if (!tag[j]) {
				tag[j] = 1;
				ans += milk[i].first;
				break;
			}
		}
	}	
	cout << ans;
//	int t; cin >> t; while (t--) solve();
	return 0;
}
