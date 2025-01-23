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

int pi[(int)1e6 + 5];
void solve() {
	stg b; cin >> b;b = ' ' + b;
  int m = b.size() - 1;
  int j = 0;
  rep(i, 2, m) {
    while (j > 0 && b[i] != b[j + 1]) j = pi[j];
    if (b[i] == b[j + 1]) j++;
    pi[i] = j;
  }
  ll sum = 1;
  rep(i, 2, m) {
    int tmp = (!!pi[i] + pi[min(i / 2, pi[i])]) + 1;
    //cout << tmp << " ";
    //tmp %= (int)1e9 + 7;
    sum *= tmp;
    sum %= (int)1e9 + 7;
  }
  cout << sum << endl;
}


main() {
int t; cin >> t; while (t--) solve();
}
