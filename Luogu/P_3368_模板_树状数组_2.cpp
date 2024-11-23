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

int arr[500005], c[500005];
int lowbit(int x) { return x & -x; }
void update(int x, int v) {
  while (x < 500005) {
    c[x] += v;
    x += lowbit(x);
  }
}
int query(int x) {
  int res = 0;
  while (x > 0) {
    res += c[x];
    x -= lowbit(x);
  }
  return res;
}


main() {
  //  int t; cin >> t; while (t--) solve();
  int n, t;
  cin >> n >> t;
  rep(i, 1, n) {
    cin >> arr[i];
  }
  while (t--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int l, r, k;
      cin >> l >> r >> k;
      update(l, k);
      update(r + 1, -k);
    } else {
      int x; cin >> x;
      cout << arr[x] + query(x) << endl;
    }
  } 
  return 0;
}