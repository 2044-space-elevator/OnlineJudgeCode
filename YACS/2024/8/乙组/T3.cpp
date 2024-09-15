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

int n, arr[(int)3e5 + 5];
int ans = 0;
void dfs(int now, int depth) {
  ans = max(ans, now);
  if (depth > n) {
    return;
  } 
  dfs(now ^ arr[depth], depth + 1);
  dfs(now, depth + 1);
}

main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) cin >> arr[i];
  dfs(0, 1);
  cout << ans;
  return 0;
}