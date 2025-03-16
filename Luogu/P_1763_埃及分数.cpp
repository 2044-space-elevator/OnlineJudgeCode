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
#define int int64_t
int X[103], Ans[103];
bool flg = 0;
void dfs(int limit, int depth, int last, int a, int b) {
  if (a == 1 && b > last) {
    flg = 1;
    X[depth] = b;
    if (Ans[depth] && Ans[depth] <= X[depth]) {
      return;
    }
      rep(i, 1, depth) Ans[i] = X[i];
    return;
  }
  if (depth == limit) return;
  int left = max(last + 1, (b - 1) / a + 1);
  int right = min((limit - depth) * b / a, (int)1e7);
  rep(i, left, right) {
    int af = a * i -  b;
    int bf = b * i;
    int ggg = __gcd(af, bf);
    af /= ggg; bf /= ggg;
    X[depth] = i;
    dfs(limit, depth + 1, i, af, bf);
  }
}


main() {
//	int t; cin >> t; while (t--) solve();
  int a, b;
  cin >> a >> b;
  for (int limit = 2; ; limit++) {
    dfs(limit, 1, 1, a, b);
    if (flg) {
      repq(i, 1, limit) cout << Ans[i] << " ";
      return 0;
    }
  }
	return 0;
}
