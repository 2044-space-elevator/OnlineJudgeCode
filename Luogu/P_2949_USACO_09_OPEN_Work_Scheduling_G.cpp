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

const int N = 1e5 + 5;

struct node {
  int t, p;
}w[N];
int n;
ll ans;
priority_queue<int, vector<int>, greater<int> > q;
bool cmp(node a, node b) {
	return a.t < b.t;
}


main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) cin >> w[i].t >> w[i].p;
  sort(w + 1, w + n + 1, cmp);
  rep(i, 1, n) {
    if (w[i].t <= q.size() && w[i].p > q.top()) {
      ans -= q.top();
      q.pop();
      q.push(w[i].p);
      ans += w[i].p;
    } else if (w[i].t > q.size()) {
      q.push(w[i].p);
      ans += w[i].p;
    }
  }
  cout << ans;
	return 0;
}
