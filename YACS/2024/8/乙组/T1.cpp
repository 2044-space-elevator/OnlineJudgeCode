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

int arr[(int)1e5 + 5];

main() {
  //  int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) {
    int l, r;
    cin >> l >> r;
    arr[r + 1]--;
    arr[l]++;
  }
  rep(i, 1, n) {
    arr[i] += arr[i - 1];
    if (!arr[i]) { RTN; return 0; }
  }
  RTY
  return 0;
}