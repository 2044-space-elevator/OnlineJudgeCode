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
#define int ll
int arr[(int)1e5 + 5], brr[(int)1e5 + 5];
void solve() {
  int n, m, h;
  cin >> n >> m >> h;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, m) cin >> brr[i];
  sort(arr + 1, arr + n + 1);
  sort(brr + 1, brr + m + 1);
  int pt1 = n, pt2 = m;
  int res = 0;
  while (pt1 && pt2) {
    res += min(arr[pt1], brr[pt2] * h);
    pt1--, pt2--;
  }
  cout << res << endl;
}


main() {
    int t; cin >> t; while (t--) solve();
  return 0;
}