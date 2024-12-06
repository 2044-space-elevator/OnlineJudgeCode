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

#define int ll

const int N = 1e5 + 7;
int n, m, arr[N];

int lowbit (int x) {return x & -x;}
void update(int x, int v) {
  for (int i = x; i <= n; i += lowbit(i)) arr[i] += v;
}
ll query(int x) {
  int res = 0;
  for (int i = x; i > 0; i -= lowbit(i)) res += arr[i];
  return res;
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  while (m--) {
    char op;
    cin >> op;
    if (op == 'x') {
      int a, b;
      cin >> a >> b;
      update(a, b);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(r) - query(l - 1) << endl;
    }
  }
	return 0;
}
