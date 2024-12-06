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

int n, k;
int arr[(int)2e5 + 5], brr[(int)2e5 + 5], mx[(int)2e5 + 5][32], mn[(int)2e5 + 5][32];
int searchmx(int l, int r) {
  int d = log2(r - l + 1);
  return max(mx[l][d], mx[r - (1 << d) + 1][d]);
} 
int searchmn(int l, int r) {
  int d = log2(r - l + 1);
  return min(mn[l][d], mn[r - (1 << d) + 1][d]);
}

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> n >> k;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, n) brr[arr[i]] = i;
  memset(mn, 127, sizeof mn);
  rep(i, 1, n) mx[i][0] = mn[i][0] = brr[i];
  for (int j = 1; 1 << j <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    }
  }
  int mn = INT_MAX;
  rep(i, 1, n) {
    if (i + k - 1 > n) continue;
    mn = min(mn, searchmx(i, i + k - 1) - searchmn(i, i + k - 1));
  }
  cout << mn;
	return 0;
}
