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

#define int ull
int n;
stg s[(int)5e5 + 5];
map<stg, bool > tmp;

main() {
  cin >> n;
  rep(i, 1, n) { cin >> s[i]; s[i] = " " + s[i]; tmp[s[i]] = 1; }
  int cnt = 0;
  for (auto [key, value] : tmp) {
    cnt++;
  }
  cout << cnt;
  return 0;

}