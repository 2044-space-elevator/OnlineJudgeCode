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


main() {
  //  int t; cin >> t; while (t--) solve();
  int k;
  stg n, m;
  cin >> k >> n >> m;
  while (n.size() < m.size()) {
    n = ' ' + n;
  }
  while (n.size() > m.size()) {
    m = ' ' + m;
  }
  int cnt = 0;
  repq(i, 0, n.size() - 1) {
    if (n[i] == m[i]) {
      continue;
    }
    n[i] = m[i];
    cnt++;
    if (cnt >= k || i == n.size() - 1) {
      int pt = i + 1;
      while (n[pt] > m[pt]) {
        n[pt - 1]--;
        if (n[pt - 1] <= '0') {
          
        }
      }
    }
    if (cnt >= k || i == n.size() - 1) {

      if (n[i + 1] > m[i + 1]) {
        n[i]--;
        if (n[i] <= '0') {
          n[i - 1]--;
          n[i]++;
        }
      }
      break;
    }
  }
  int pt = n.size() - 1;
  while (cnt < k) {
    n[pt]--;
    if (n[pt] <= '0') {
      n[pt - 1]--;
      n[pt] = '9';
    }
    cnt++;
    pt--;
  }
  cout << n;
  return 0;
}