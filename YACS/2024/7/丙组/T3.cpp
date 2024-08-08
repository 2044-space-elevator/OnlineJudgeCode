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

struct redd {
  int first, second;
};

bool operator<(const redd &a, const redd &b) {
  return a.second < b.second;
}

redd times[200005];
main() {
  //  int t; cin >> t; while (t--) solve();
  int n;
  cin >> n;
  rep(i, 1, n) {
    cin >> times[i].first >> times[i].second;
  }
  sort(times + 1, times + n + 1);
  int cnt = 0;
  int last = 0;
  rep(i, 1, n) {
    if (times[i].first >= times[last].second) {
      last = i;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}