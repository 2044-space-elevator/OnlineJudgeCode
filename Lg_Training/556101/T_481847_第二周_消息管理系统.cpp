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
int que[10005], l = 1, r = 0;

void solve() {
  int op;
  cin >> op;
  if (op == 1) {
    int x;
    cin >> x;
    r++;
    que[r] = x;
  }
  if (op == 2) {
    if (l > r) {
      cout << "ERR_CANNOT_POP\n";
    }
    else l++;
  }
  if (op == 3) {
    if (l > r) cout << "ERR_CANNOT_QUERY\n";
    else cout << que[l] << endl;
  }
  if (op == 4) {
    cout << r - l + 1 << endl;
  }
}



main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
