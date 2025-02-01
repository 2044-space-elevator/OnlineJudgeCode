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

#define int ull
struct node {
  int x, num;
};
stack<node> s;
main() {
//	int t; cin >> t; while (t--) solve();
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int ans = 0;
  int n; cin >> n;
  rep(i, 1, n) {
    int x;
    cin >> x;
    while (s.size() && s.top().x < x) {
      ans ^= s.top().num;
      s.pop();
    }
    s.push({x, i});
    ans ^= i;
  cout << ans << endl;
  }
	return 0;
}
