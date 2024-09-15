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

int n, arr[5005], brr[5005];
bool permu[5005];
int ans = INT_MAX;

void dfs(int depth) {
  if (depth > n) {
    int tmp = 0;
    rep(i, 1, n) {
      rep(dis, 0, n) {
        if (i + dis <= n) {
          if (permu[i + dis]) {
            tmp += arr[i] * dis;
            break;
          } 
        }
        if (i - dis >= 1) {
          if (permu[i - dis]) {
            tmp += arr[i] * dis;
            break;
          } 
        }
      } 
      rep(dis, 0, n) {
        if (i + dis <= n) {
          if (!permu[i + dis]) {
            tmp += arr[i] * dis;
            break;
          } 
        }
        if (i - dis >= 1) {
          if (!permu[i - dis]) {
            tmp += arr[i] * dis;
            break;
          } 
        }
      } 
    }
    ans = min(tmp, ans);
  }
  dfs(depth + 1);
  permu[depth] = 1;
  dfs(depth + 1);
}

main() {
  //  int t; cin >> t; while (t--) solve();
  cin >> n;
  rep(i, 1, n) {
    cin >> arr[i] >> brr[i];
  }
  dfs(1); 
  cout << ans;
  return 0;
}
