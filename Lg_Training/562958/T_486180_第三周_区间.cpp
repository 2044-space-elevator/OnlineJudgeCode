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

int arr[1000005];
main() {
  //  int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) {
    int a, b;
    cin >> a >> b;
    arr[a]++;
    arr[b + 1]--;
  }
  rep(i, 1, 1000005) arr[i] += arr[i - 1];
  int ans = 0;
  rep(i, 1, 1000005) {
    ans = max(ans, arr[i]);
  }
  cout << ans;
  return 0;
}