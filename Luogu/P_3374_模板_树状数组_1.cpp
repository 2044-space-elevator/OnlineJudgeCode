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
const int N = 5E5 + 5;

int c[N], n, t;
int arr[N];
int lowbit(int x) { return x & -x; }
void update(int x, int val) {
  for (int i = x; i <= n; i += lowbit(i)) c[i] += val;
}

int query(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) ans += c[i];
  return ans;
}

main() {
//	int t; cin >> t; while (t--) solve();
cin >> n >> t;
  rep(i, 1, n) { cin >> arr[i]; update(i, arr[i]); }
  while (t--) {
    int typ;
    cin >> typ;
    if (typ == 2) {
      int l, r;
      cin >> l >> r;
      cout << query(r) - query(l - 1) << endl;
    } else {
      int x, y;
      cin >> x >> y;
      update(x, y);
    }
  }
	return 0;
}