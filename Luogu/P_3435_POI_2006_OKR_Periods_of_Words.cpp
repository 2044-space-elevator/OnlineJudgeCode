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

stg a, b;
const int N = 1e6 + 5;
int pi[N];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> a >> b;
  a = " " + a; b = " " + b;
  int n = a.size() - 1, m = b.size() - 1;
  int j = 0;
  rep(i, 2, m) {
    while (j > 0 && b[i] != b[j + 1]) j = pi[j];
    if (b[i] == b[j + 1]) j++;
    pi[i] = j;
  }
  ll sum = 0;
  rep(i, 2, m) {
    int j = i;
    while (pi[j]) j = pi[j];
    sum += i - j;
  }
  cout << sum;
	return 0;
}
