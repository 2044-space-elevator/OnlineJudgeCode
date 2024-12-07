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

const int N = 2e6 + 5;
int n, m,mn[N][22];

int search(int l, int r) {int d = log2(r - l + 1);
    int res2 = min(mn[l][d], mn[r - (1 << d) + 1][d]);
    return res2;
    }
main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> m;
  rep(i, 1, n) { cin >> mn[i][0];}
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i < 2) {
      cout << "0\n";
    } else 
    cout << search(max(1, i - m), i - 1) << '\n';
  }
	return 0;
}