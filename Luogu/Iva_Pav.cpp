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
int st[(int)2e5 + 5][32];

int search(int l, int r) {
  int d = log2(r - l + 1);
  return st[l][d] & st[r - (1 << d) + 1][d];
}

void solve() {
  int n;
  cin >> n;
  memset(st, 0, sizeof st);
  rep(i, 1, n) cin >> st[i][0];
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      st[i][j] = st[i][j - 1] & st[i + (1 << (j - 1))][j - 1];
  int q;
  cin >> q;
  while (q--) {
    int l, k;
    cin >> l >> k;
    if (st[l][0] < k) { cout << "-1 "; continue; }
    int left = l, right = n;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (search(l, mid) >= k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    cout << left - 1 << " ";
    _:;
  }
  cout << endl;
}


main() {
	int t; cin >> t; while (t--) solve();
	return 0;
}
