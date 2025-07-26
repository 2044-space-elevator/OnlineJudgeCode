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

int n, m, arr[(int)5e5 + 5];

main() {
//	int t; cin >> t; while (t--) solve();
    cin >> n >> m;
    rep(i, 1, n) { cin >> arr[i]; arr[i] += arr[i - 1]; }
    deque<int> q;
    q.clear();
    q.push_back(0);
    int ans = INT_MIN;
    rep(i, 1, n) {
        while (q.size() && q.front() < i - m) q.pop_front();
        ans = max(ans, arr[i] - arr[q.front()]);
        while (q.size() && arr[q.back()] >= arr[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << ans;
	return 0;
}
