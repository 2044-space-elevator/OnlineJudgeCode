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

int arr[(int)2e5 + 5], sum[(int)2e5 + 5];

main() {
  //  int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) cin >> arr[i];
  rep(i, 1, n) sum[i] = arr[i] + sum[i - 1];
  int ind = 0;
  rep(i, 1, n) {
    if (sum[i] >= 0) {
      ind = i;
    }
  }
  cout << ind;
  return 0;
}