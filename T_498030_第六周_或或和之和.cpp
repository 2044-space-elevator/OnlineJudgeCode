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

int ST[500005][32], sum[500005];

int query(int l, int r) {
  int k = log2(r - l + 1);
  return ST[l][k] | ST[r - (1 << k) + 1][k];
}

main() {
//	int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) {
    cin >> ST[i][0];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n - (1 << (j - 1)) + 1; i++) {
      ST[i][j] = ST[i][j - 1] | ST[i + (1 << (j - 1))][j - 1];
    }
  }
}
