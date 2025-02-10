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

priority_queue<int, vector<int>, greater<int> > q;
void solve() {
  int op;
  cin >> op;
  if (op == 1) {
    int x;
    cin >> x;
    q.push(x);
  }
  if (op == 2) {
    cout << q.top() << endl;
  }
  if (op == 3) {
    q.pop();
  }
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
