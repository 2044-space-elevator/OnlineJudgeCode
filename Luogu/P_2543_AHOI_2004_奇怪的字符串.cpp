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

stg zhaoxiaolong, lienchun;
int xiahaorui[4][10000];

main() {
//	int t; cin >> t; while (t--) solve();
  cin >> zhaoxiaolong >> lienchun;
  zhaoxiaolong = " " + zhaoxiaolong; lienchun = " " + lienchun;
  repq(i, 1, zhaoxiaolong.length()) {
    repq(j, 1, lienchun.length()) {
      xiahaorui[i % 2][j] = max(xiahaorui[(i - 1) % 2][j], xiahaorui[i % 2][j - 1]);
      xiahaorui[i % 2][j] = max(xiahaorui[i % 2][j], xiahaorui[(i - 1) % 2][j - 1]+ (zhaoxiaolong[i] == lienchun[j]));
    }
  } 
  cout << xiahaorui[(zhaoxiaolong.length() - 1) % 2][lienchun.length() - 1];
	return 0;
}
