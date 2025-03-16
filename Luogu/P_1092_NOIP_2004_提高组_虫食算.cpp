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

bool correct() {
  if ()
}

int n;
stg a, b, c;
bool used[105];
int order[105];
int num[105];
int tot;

void dfs(int x) {
  if (x == n) {
    if (correct()) {
      rep(i, 'A', 'A' + n - 1) {
        cout << order[i] << " ";
      }
      exit(0);
    }
    return;
  }
}

main() {
//	int t; cin >> t; while (t--) solve();
cin >> n;
  cin >> a >> b >> c;
  dfs(1);

	return 0;
}
