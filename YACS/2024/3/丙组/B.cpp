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
#define int ll

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  
}


main() {
  //  int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  if (n <= 2) cout << "Arithmetic Sequence";
  int n1, n2;
  cin >> n1 >> n2;
  int dif = n2 - n1;
  int last = n2;
  rep(i, 3, n) {
    int x;
    cin >> x;
    if (x - last != dif) {
      cout << "No\n";
      return 0;
    }
    last = x;
  }
  cout << "Arithmetic Sequence";
  return 0;
}