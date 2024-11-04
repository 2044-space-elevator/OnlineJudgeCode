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

priority_queue<int, vector<int>, greater<int> > pq;

main() {
//	int t; cin >> t; while (t--) solve();
  int n; cin >> n;
  rep(i, 1, n) {int x; cin >> x; pq.push(x);}
  int sum = 0;
  while (pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    sum += a + b;
    pq.push(a + b);
  }
  cout << sum;
	return 0;
}
